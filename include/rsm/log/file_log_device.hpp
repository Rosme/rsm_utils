/*
* Copyright (c) 2018 Jean-S�bastien Fauteux
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from
* the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it freely,
* subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not claim
*    that you wrote the original software. If you use this software in a product,
*    an acknowledgment in the product documentation would be appreciated but is
*    not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/

#pragma once

#include <rsm/log/log_device.hpp>
#include <fstream>
#include <stdexcept>

namespace rsm {
	
	class FileLogDevice
		: public LogDevice {

	public:
		FileLogDevice(const std::string& fileName) {
			m_file.open(fileName, std::ios::out | std::ios::trunc);
			if(!m_file.is_open()) {
				throw std::runtime_error("Impossible to create the log file");
			}
		}

		void log(LogLevel level, const std::string& message) override {
			m_file << "[" << logLevelToString(level) << "]" << message << "\n";
		}

	private:
		std::ofstream m_file;
	};

}
