# -*- coding: utf-8 -*-
import sys
import matplotlib.pyplot as pyplot
import matplotlib.mlab as mlab
import matplotlib as mpl
import matplotlib.cm as cm
import numpy as np
import math
from itertools import product
from shapely.geometry import LineString, Point
from scipy import stats
import pygmaps 
import webbrowser 
import colorsys

#Plots a heatmap & google map showing where next top analyst could be found
#Rules dictate it is likely to be close to the river Spree, close to the Brandenburg Gate, and close to the satellite path

# longitude：经度； latitude：纬度

def viewProbHeatMaps(lonAxisStart, lonAxisStop, lonAxisInterval, latAxisStart, latAxisStop, latAxisInterval):
	#create grid of map points
	mapPoints = getAllPoints(lonAxisStart, lonAxisStop, lonAxisInterval, latAxisStart, latAxisStop, latAxisInterval)

	#for each grid point - get probability analyst is at this location
	#caculate probability according to river rule
	probFromRiver = riverRule(mapPoints, 0, 2730/2, 6371) # sigma = 2730/1.96，这里除以2是错误的

	#calculate probability according to Barangenburg Gate rule
	probFromGate = gateRule(mapPoints, 4700, 3877, 13.377689, 52.516288, 6371)

	#calculate probability according to satellite rule
	probFromSatellite = satelliteRule(mapPoints, 13.39915, 52.590117, 13.553989, 52.437385, 6371, 2400/2, 0) # sigma = 2400/1.96，这里除以2是错误的

	#compile all probabilities
	probTotal = compileProbs(probFromRiver, probFromGate, probFromSatellite)

	#plot total heatmap on map - to see where analyst is likely to be found
	plotOnMap(lonAxisStart, lonAxisStop, latAxisStart, latAxisStop, probFromRiver, mapPoints, 0, 0.0003)
	plotOnMap(lonAxisStart, lonAxisStop, latAxisStart, latAxisStop, probFromGate, mapPoints, 0, 0.0003)
	plotOnMap(lonAxisStart, lonAxisStop, latAxisStart, latAxisStop, probFromSatellite, mapPoints, 0, 0.0003)

	plotOnMap(lonAxisStart, lonAxisStop, latAxisStart, latAxisStop, probTotal, mapPoints, 0, 0.000000000001)

	#plot heatmap of all probabilities - to see what probability each latitude & longitude has
	plotHeatMap(probTotal, mapPoints)

	#plot heatmap of each probability - not using this for now, but useful code for further analysis
	#plotHeatMap(probFromRiver, mapPoints)
	#plotHeatMap(probFromGate, mapPoints)
	#plotHeatMap(probFromSatellite, mapPoints)

def getAllPoints(lonStart, lonStop, lonInterval, latStart, latStop, latInterval): # 经纬度网格点
	mapPointsLon = np.linspace(lonStart, lonStop, num=lonInterval)
	mapPointsLat = np.linspace(latStart, latStop, num=latInterval)
	mapPointsLonAll, mapPointsLatAll = np.meshgrid(mapPointsLon, mapPointsLat) 
	allPoints = []
	for i in range(0, len(mapPointsLonAll)):
		for j in range(0, len(mapPointsLonAll[i])):
			allPoints.append([mapPointsLonAll[i][j],mapPointsLatAll[i][j]])
	return allPoints

def riverRule(allPoints, mu, sigma, earthR): # 计算河流的概率密度
	#get river coordinates
	riverCoords = getRiverCoords() # 获取河流坐标

	#loop through map to get probabilities of analyst being at location - due to river
	probRivers=[]
	for coords in allPoints:
		iLon, iLat = getLonLat(coords) # 经度，纬度

		#find shortest distance from river
		shortestDis = getShortestDisLinePoint(iLon, iLat, riverCoords, earthR)

		#for distance from river, get prob of analyst existence
		probRiver = mlab.normpdf(shortestDis,mu,sigma) # 计算概率
		probRivers.append(probRiver)
	return probRivers

def getRiverCoords(): # 获取河流的GPS坐标
	#parse txt file and create list of river GPS coords
	riverFile = open("River Spree.txt")
	#riverFile = open(sys.argv[1])
	riverCoords = []
	for line in riverFile:
		lat, lon = line.split(",") # txt (N, E) 纬度，经度
		riverCoords.append([float(lon), float(lat)]) # [经度，纬度]
	return riverCoords

def getLonLat(coordPair):
	lon = coordPair[0] #经度
	lat = coordPair[1] #纬度
	return lon, lat

def getShortestDisLinePoint(pointLon, pointLat, lineCoords, earthR): # 获取点到直线的最短距离
	#get shortest distance between point and line
	line = LineString(lineCoords) # http://toblerity.org/shapely/manual.html
	point = Point(pointLon, pointLat)
	closestCoord = line.interpolate(line.project(point)) # 获取距离最近的点
	distance = haversine(pointLon, pointLat, closestCoord.x, closestCoord.y, earthR)
	return distance

def gateRule(allPoints, mu, mode, fixedPointLon, fixedPointLat, earthR):
	#find sd using mode(X)=exp(mu-var)
	var = mu-math.log(mode)
	sigma = math.sqrt(var)

	#I have spent some time trying to get lognorm function to work, this calc of mu & sigma feels wrong - I'm a bit stuck
	muLog = np.log(mu)
	sigmaLog = np.log(sigma)
	
	#loop through map to get probabilities of analyst being at location - due to gate
	probGates=[]
	for coords in allPoints:
		iLon, iLat = getLonLat(coords)

		#find shortest distance from gate
		shortestDis = haversine(iLon, iLat, fixedPointLon, fixedPointLat, earthR)

		#for distance from gate, get prob of analyst existence
		if shortestDis > 0:
			probGate = stats.lognorm.pdf(shortestDis, sigmaLog, 0, np.exp(muLog))
		else:
			probGate = 0

		probGates.append(probGate)
	return probGates

def haversine(lon1, lat1, lon2, lat2, earthR): # https://en.wikipedia.org/wiki/Haversine_formula
    """
    Calculate the great circle distance between two points 
    on the earth (specified in decimal degrees)
    """
    # convert decimal degrees to radians 
    lon1, lat1, lon2, lat2 = map(math.radians, [lon1, lat1, lon2, lat2]) #将经纬度转成弧度

    # haversine formula 
    dlon = lon2 - lon1 
    dlat = lat2 - lat1 
    a = math.sin(dlat/2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon/2)**2
    c = 2 * math.asin(math.sqrt(a)) 

    metres = earthR * c * 1000

    return metres 

def lognstat(mu, sigma):
	#perhaps I should be using this to get lognorm mu & sigma, but then lognorm function doesn't work
    """Calculate the mean of and variance of the lognormal distribution given
    the mean (`mu`) and standard deviation (`sigma`), of the associated normal 
    distribution."""
    m = np.exp(mu + sigma**2 / 2.0)
    v = np.exp(2 * mu + sigma**2) * (np.exp(sigma**2) - 1)
    return m, v

def satelliteRule(allPoints, lonStart, latStart, lonEnd, latEnd, earthR, sigma, mu):
	#get satellite path coordinates
	pathCoords = ([lonStart, latStart], [lonEnd, latEnd])

	#loop through map to get probabilities of analyst being at location - due to river
	probPaths=[]
	for coords in allPoints:
		iLon, iLat = getLonLat(coords)

		#find shortest distance from river
		shortestDis = getShortestDisLinePoint(iLon, iLat, pathCoords, earthR)

		#for distance from river, get prob of analyst existence
		probPath = mlab.normpdf(shortestDis, mu, sigma)
		probPaths.append(probPath)
	return probPaths

def compileProbs(probs1, probs2, probs3):  # 联合概率密度
	totalProbs = []
	for i in range(0, len(probs1)):
		totalProb = probs1[i] * probs2[i] * probs3[i]
		totalProbs.append(totalProb)
	return totalProbs

def plotHeatMap(prob, allPoints):
	pyplot.scatter(list(zip(*allPoints)[0]), list(zip(*allPoints)[1]), c=prob, s=100, edgecolors='none', marker="h")
	pyplot.colorbar().set_label('probability of finding top analyst')
	pyplot.show()

def plotOnMap(lonAxisStart, lonAxisStop, latAxisStart, latAxisStop, prob, allPoints, vmin, vmax):
	lat1 = latAxisStart + ((latAxisStop-latAxisStart)/2)
	lon1 = lonAxisStart + ((lonAxisStop-lonAxisStart)/2)
	mymap = pygmaps.maps(lat1, lon1, 12)

	addMapPoints(prob, allPoints, mymap, vmin, vmax)

	mymap.draw('mymap.draw.html') 
	url = 'mymap.draw.html'
	webbrowser.open_new_tab(url) 

def addMapPoints(prob, allPoints, mymap, vmin, vmax):
	colourScale = setColourScale(vmin, vmax)
	for i in range(0,len(allPoints)):
		pointColour = getColor(prob[i], colourScale)
		mymap.addpoint(allPoints[i][1], allPoints[i][0], pointColour) 

def setColourScale(vmin, vmax):
	norm = mpl.colors.Normalize(vmin, vmax)
	cmap = cm.rainbow
	m = cm.ScalarMappable(norm=norm, cmap=cmap)
	return m

def getColor(val, m):
	rgb = m.to_rgba(val, 0.5)
	hexColour = mpl.colors.rgb2hex(rgb)
	return hexColour

def main():
	#view probability heat maps
	viewProbHeatMaps(13.2, 13.8, 100, 52.2, 52.8, 100)

if __name__ == '__main__':
	main()