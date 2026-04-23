#pragma once //include guard

char *strtok(char * __restrict str, const char * __restrict delim) {
	static char *next_token = nullptr;
	static char *current_string = nullptr;
	
	// If str is not null, this is the first call for a new string
	if (str != nullptr) {
		current_string = str;
		next_token = str;
	}
	
	// If we've reached the end, return nullptr
	if (current_string == nullptr || *current_string == '\0') {
		return nullptr;
	}
	
	// Skip leading delimiters
	while (*current_string != '\0') {
		bool is_delim = false;
		const char *d = delim;
		while (*d != '\0') {
			if (*current_string == *d) {
				is_delim = true;
				break;
			}
			d++;
		}
		if (!is_delim) {
			break;
		}
		current_string++;
	}
	
	// If we've reached the end after skipping delimiters, return nullptr
	if (*current_string == '\0') {
		return nullptr;
	}
	
	// This is the start of our token
	char *token_start = current_string;
	
	// Find the next delimiter
	while (*current_string != '\0') {
		bool is_delim = false;
		const char *d = delim;
		while (*d != '\0') {
			if (*current_string == *d) {
				is_delim = true;
				break;
			}
			d++;
		}
		if (is_delim) {
			break;
		}
		current_string++;
	}
	
	// If we found a delimiter, replace it with '\0' and move to next character
	if (*current_string != '\0') {
		*current_string = '\0';
		current_string++;
	}
	
	return token_start;
}


