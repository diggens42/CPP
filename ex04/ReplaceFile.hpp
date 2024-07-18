/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:20:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/18 18:37:18 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP
#include <string>
#include <iostream>
#include <fstream>

class ReplaceFile
{
	private:
		std::string _filename;
		std::string	_string1;
		std::string _string2;

		std::string read_file();
		void		write_file(const std::string& content);
		std::string	replace_match(const std::string& content);

	public:
		ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2);
		~ReplaceFile();
		void	replacing();
};
#endif
