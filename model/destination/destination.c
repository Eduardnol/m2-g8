#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include "destination.h"
#include "../../logic/utils/utils.h"

#define toRadians(degrees) ((degrees) * M_PI / 180.0)

#define TIME_FACTOR 3.7

#define DIRECTIONS 4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

double haversine(double ang) {
	return pow(sin(ang / 2), 2.0);
}

// Distància haversine des de BCN
double getDistanceFromBcn(Destination dest) {
	Destination bcn;
	bcn.location.lat = BCN_LON;
	bcn.location.lon = BCN_LAT;

	return getDistanceBetween(bcn, dest);
}

// Distància haversine
double getDistanceBetween(Destination this, Destination that) {
	double latA = toRadians(this.location.lat);
	double latB = toRadians(that.location.lat);
	double lonA = toRadians(this.location.lon);
	double lonB = toRadians(that.location.lon);

	double angleCentral = haversine(latA - latB);
	angleCentral += cos(latA) * cos(latB) * haversine(lonA - lonB);
	angleCentral = 2 * asin(sqrt(angleCentral));

	return EARTH_RADIUS * angleCentral;
}

// Retorna la mitjana de preus d'hotels
double getAverageHotelPrice(Destination dest) {
	double average = 0.0;
	int i;

	for (i = 1; i < dest.nHotels; i++) {
		average += *(dest.hotelPrices + i) / dest.nHotels;
	}

	return average;
}
