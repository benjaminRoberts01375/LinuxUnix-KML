/**
 * @file earth_utils.h
 * @brief Lecture 10.2 code – handles parsing a lat/long csv file and conversion of that to kml
 * @author Ben Roberts
 * @credits Bilbo (Devin) Baggins
 * @assignment Lecture 10.2
 * @date 11/11/20
 */

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

const std::string PLACEMARK = "<Placemark>";
const std::string PLACEMARK_END = "</Placemark>";
const std::string NAME = "<name>";
const std::string NAME_END = "</name>";
const std::string COORDS = "<Point><coordinates>";
const std::string COORDS_END = "</coordinates></Point>";


/**
 * @brief designed to work with capital csv file
 * @date 11/11/2020
 * @return a bool indicating the message was written
 * @param inFile ifstream to an opened and validated csv file
 * @param kmlFileName string containing the name of the kml file to produce
 */
int processCSV(std::ifstream& inFile, std::string kmlFileName);

/**
 * @brief Writes a Placemark Record into an existing kml file
 * @date 11/11/2020
 * @param kmlFile an ofstream of the file to write to
 * @param name a string of the capital and country
 * @param latitude string representing lat
 * @param longitude string representing long
 */
void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude);

#endif