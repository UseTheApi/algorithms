//
//  dinner_party.cpp
//  algorithms. dinner_party
//
//  Created by alifar on 01/26/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> CombineFriends(const std::vector<char> &friends, const int table_size, int pos, std::string group, std::vector<std::string> groups){
	if(group.size() == table_size){
		groups.push_back(group);
	} else if(pos < friends.size()){
		groups = CombineFriends(friends, table_size, pos+1, group, groups); // case when we don't add friends[pos] to table
		group.push_back(friends[pos]);
		groups = CombineFriends(friends, table_size, pos+1, group, groups); // case when we added friends[pos] to table
	}
	return groups;
}


std::vector<std::string> DinnerParties(const std::vector<char> &friends, const int table_size){
	std::string g;
	std::vector<std::string> groups;
	groups = CombineFriends(friends, table_size, 0, g, groups);
	return groups;
}

