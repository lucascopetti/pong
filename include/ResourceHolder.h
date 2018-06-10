/*
 * ResourceHolder.h
 *
 *  Created on: Jun 5, 2018
 *      Author: lucas
 */

#ifndef INCLUDE_RESOURCEHOLDER_H_
#define INCLUDE_RESOURCEHOLDER_H_

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{
	private:
		std::map<Identifier, std::unique_ptr<Resource>>	_resourceMap;
	public:
		void						load(Identifier id, const std::string& filename);

		template <typename Parameter>
		void						load(Identifier id, const std::string& filename, const Parameter& secondParam);

		Resource&					get(Identifier id);
		const Resource&				get(Identifier id) const;


	private:
		void						insertResource(Identifier id, std::unique_ptr<Resource> resource);



};

#include "ResourceHolder.inl"

#endif /* INCLUDE_RESOURCEHOLDER_H_ */
