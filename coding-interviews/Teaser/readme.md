#Data science challenge using Python & Stats
Please find code and plots at https://github.com/sarahleejane/Next-Top-Analyst

##Details of the problem
This is about searching for a new top analyst. We already know of an excellent candidate with top analytical and programming skills. Unfortunately, we don't know her exact whereabouts but we only have some vague information where she might be. Can you tell us where to best send our recruiters and plot an easy to read map of your solution for them?

This is what we could extract from independent sources:

* The candidate is likely to be close to the river Spree. The probability at any point is given by a Gaussian function of its shortest distance to the river. The function peaks at zero and has 95% of its total integral within +/-2730m.
* A probability distribution centred around the Brandenburg Gate also informs us of the candidate's location. The distribution’s radial profile is log-normal with a mean of 4700m and a mode of 3877m in every direction.
* A satellite offers further information: with 95% probability she is located within 2400 m distance of the satellite’s path (assuming a normal probability distribution)

##Solution to the problem
I created the script *Next Top Analyst.py* to analyse and combine the 3 clues.

I plotted the probability from each clue onto Google Maps, so we can visualise each clue.
I then plotted the combined probabilities onto Google Maps, and in a Heat Map, so we can see the location and probability of finding the next top analyst respectively.

The Heat Map shows us a concentrated location where there is a 0.000000000001 chance of them being in this localised area.
The Google Map plot tells us the area is around Heizkraftwerk Klingenberg.  This is a thermal power plant in Berlin - it could be worth a visit to find the next top analyst!

There is a larger area where there is at least a 0.0000000000004 chance of them being in the area.
This area includes Friedrichshain.  Wikipedia tells me this is an area known for it's fashionable bars and clubs, so having a fun night out could be a good way to find the next top analyst.  It appears to attract students, so maybe this analyst is a student, in which case advertising at their place of study could be a good tactic.

This area also includes Oberschöneweide, which is home to Hochschule für Technik und Wirtschaft, the University of Applied Sciences & Engineering.  We could very well find the next top analyst at this university!

##Ongoing questions
The lognormal distribution was tough to plot.  I am not convinced I have used the correct mu and sigma for the log normal distribution.  This requires further research.