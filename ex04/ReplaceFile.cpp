/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:27:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/18 19:07:00 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

ReplaceFile::ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2) : _filename(filename), _string1(s1), _string2(s2) {}

ReplaceFile::~ReplaceFile(){}

void	ReplaceFile::replacing()
{
	std::string	content;
	std::string replaced_content;

	content = read_file();
	replaced_content = replace_match(content);
	write_file(replaced_content);
}

std::string ReplaceFile::read_file()
{
	std::ifstream file(_filename);
	if (!file.is_open())
		throw std::runtime_error("can't open input file");
	std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();
	return (content);
}

void	ReplaceFile::write_file(const std::string& content)
{
	std::string new_filename = _filename + ".replace";
	std::ofstream file(new_filename);
	if (!file.is_open())
		throw std::runtime_error("can't create output file");
	file << content;
	file.close();
}

std::string	ReplaceFile::replace_match(const std::string& content)
{
	std::string	res;
	size_t		last_pos = 0;
	size_t		find_pos;

	while ((find_pos = content.find(_string1, last_pos)) != std::string::npos)
	{
		res.append(content, last_pos, find_pos - last_pos);
		res.append(_string2);
		last_pos = find_pos + _string1.length();
	}
	res.append(content, last_pos, std::string::npos);
	return (res);
}

