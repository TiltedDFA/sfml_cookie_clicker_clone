#include "helper_functions.h"

std::string h_fun::double_to_string_2_dp(const double& input)
{
	const std::string temp = std::to_string(input);
	const auto full_stop_pos =
		std::find(temp.cbegin(), temp.cend(), '.');
	std::string to_return;
	for(auto start_pos = temp.cbegin(); start_pos < full_stop_pos + 3 ; ++start_pos)
		//this should stop 2 spots after the decimal point
	{
		to_return += *start_pos;
	}
	return to_return;
}