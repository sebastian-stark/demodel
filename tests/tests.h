/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 21.12.2022 by Sebastian Stark
 *
 * This file is part of the DEModel library
 */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

std::ofstream demodel_log;
std::string fname;

/**
 * initialize logging (open a file stream into which log output can be written)
 */
void initlog(int argc, char *argv[], std::string fname_)
{
	fname = fname_;
	const std::string log_file_name = fname + "_.log";
	demodel_log.open(log_file_name.c_str());
}

/**
 * Function used to replace CRLF by LF (sometimes required when mixing Linux and Windows machines
 * for software development).
 */
void
replace_crlf_lf(std::string& str)
{
	while(str.find("\r\n") != std::string::npos)
	    str.replace(str.find("\r\n"), 2, "\n");
    return;
}

/**
 * stop logging (compare the output of the program with sample output)
 */
int stoplog(int argc, char *argv[])
{
	demodel_log.close();
	const std::string log_file_name = fname + "_.log";
	const std::string comparison_log_file_name = fname + ".log";
	std::ifstream log_file(log_file_name.c_str());
	std::ifstream comparison_log_file(comparison_log_file_name.c_str());
	std::stringstream log_file_ss, comparison_log_file_ss;
	log_file_ss << log_file.rdbuf();
	comparison_log_file_ss << comparison_log_file.rdbuf();
	auto log_file_str = log_file_ss.str();
	auto comparison_log_file_str = comparison_log_file_ss.str();
	replace_crlf_lf(log_file_str);
	replace_crlf_lf(comparison_log_file_str);
	return (comparison_log_file_str != log_file_str);
}
