# NMEA-Display
I have been given the task of navigating in an upcoming long distance sailing
race. The boat I am racing on is not outfitted with any instruments for
navigation, so I'm using a computer and [OpenCPN](https://opencpn.org/) to plot
our course. The only issue with this setup is we would have no way to see any
status information about our current course without going below deck. To remedy
this I have created a display which decodes the
[NEMA0183](http://www.catb.org/gpsd/NMEA.html) using some spare arduino hardware
I had lying around.

I used this library for decoding the messages output by OpenCPN
https://github.com/ttlappalainen/NMEA0183
