/***************************************************************************
 *   Copyright (C) 2012 by Pierre Marchand   *
 *   pierre@oep-h.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef OSPI_PLANREADER_H
#define OSPI_PLANREADER_H

#include <string>
#include <map>

#include <boost/shared_ptr.hpp>

#include "SourcePage.h"
#include "PlanParams.h"

namespace ospi {
	
	class PlanReader
	{
		protected:
			typedef boost::shared_ptr<SourcePage> SourcePagePtr;
			typedef boost::shared_ptr<PoDoFo::PdfMemDocument> DocumentPtr;
			typedef std::pair<std::string, DocumentPtr> DocInfoKey;

			PlanReader(){}
		public:
			virtual ~PlanReader(){}
			virtual int Impose() = 0;


	};
	typedef boost::shared_ptr<PlanReader> PlanReaderPtr;



	class PlanReaderFactory
	{
		public:
			class Creator
			{
				public:
					Creator(){}
					virtual ~Creator(){}
					virtual PlanReaderPtr Create(const std::string& plan, const PlanParams& params, bool isData) = 0;
			};

		protected:
			PlanReaderFactory();
			static PlanReaderFactory* instance;
			typedef boost::shared_ptr<Creator> CreatorPtr;

			std::map<std::string, CreatorPtr> creators;

		public:
			static int Impose(const std::string& readerTS, const std::string& plan, const PlanParams& params, bool isData);

	};
	
} // namespace ospi

#endif // OSPI_PLANREADER_H
