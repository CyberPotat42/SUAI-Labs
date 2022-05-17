#include "HugeInt.h"

HugeInt::HugeInt() {
	for (int i = 0; i < 41; i++) {
		number[i] = 0;
	}
	depth = 0;
	negative = false;
}

HugeInt::HugeInt(int d) {
	for (int i = 0; i < 41; i++) {
		number[i] = 0;
	}
	depth = d;
	negative = false;
}

HugeInt::HugeInt(int num[41], int dep) {
	for (int i = 0; i < 41; i++) {
		number[i] = num[i];
	}
	depth = dep;
	negative = false;
}

void HugeInt::set(std::string str) {
	if (str[0] == '-') {
		depth = str.length() - 1;
		negative = true;
		int j = 0;
		for (int i = str.length() - 1; i > 0; i--) {
			number[j++] = str[i] - 48;
		}
	}
	else {
		depth = str.length();
		negative = false;
		int j = 0;
		for (int i = str.length() - 1; i >= 0; i--) {
			number[j++] = str[i] - 48;
		}
	}

}

std::string HugeInt::get() {
	std::string str;
	if (negative) {
		str += '-';
		for (int i = depth - 1; i >= 0; i--) {
			str += number[i] + 48;
		}
	}
	else {
		for (int i = depth - 1; i >= 0; i--) {
			str += number[i] + 48;
		}
	}

	return str;
}

bool HugeInt::check_zero() {
	for (int i = 0; i < depth; i++) {
		if (number[i]) {
			return false;
		}
	}
	return true;
}

int HugeInt::compare(HugeInt& b) {
	if (negative && !b.negative) {
		return -1;
	}
	else if (!negative && b.negative) {
		return 1;
	}
	else if (!negative && !b.negative) {
		if (depth > b.depth) {
			return 1;
		}
		else if (b.depth < depth) {
			return -1; 
		}
		else {
			for (int i = depth - 1; i >= 0; i--) {
				if (number[i] > b.number[i]) {
					return 1;
				}
				else if (number[i] < b.number[i]) {
					return -1;
				}
			}
			return 0;
		}
	}
	else if (negative && b.negative) {
		if (depth > b.depth) {
			return -1;
		}
		else if (b.depth < depth) {
			return 1;
		}
		else {
			for (int i = depth - 1; i >= 0; i--) {
				if (number[i] > b.number[i]) {
					return -1;
				}
				else if (number[i] < b.number[i]) {
					return 1;
				}
			}
			return 0;
		}
	}
}

HugeInt HugeInt::simple_sum(HugeInt& b) {
	int max = 0;
	if (depth > b.depth) {
		max = depth;
	}
	else {
		max = b.depth;
	}
	int result[41] = { 0 };
	for (int i = 0; i < max; i++) {
		int tmp = (result[i] + number[i] + b.number[i]);
		result[i] = tmp % 10;
		result[i + 1] += tmp / 10;
	}
	if (result[max]) {
		max++;
	}
	HugeInt res(result, max);
	return res;
}

HugeInt HugeInt::simple_dif(HugeInt& b) {
	int result[41] = { 0 };
	for (int i = 0; i < depth; i++) {
		result[i] = number[i] - b.number[i];
	}
	for (int i = 0; i < depth; i++) {
		if (result[i] < 0) {
			result[i] += 10;
			int j = i + 1;
			for (j; result[j] < 0; j++) {
				result[j] += 9;
				i++;
			}
			result[i + 1] -= 1;
		}
	}
	HugeInt res(result, depth);
	return res;
}

HugeInt HugeInt::sum(HugeInt& b) {
	if (!negative && !b.negative) { //+
		return this->simple_sum(b);
	}
	else if (negative && b.negative) { //+
		HugeInt result;
		result = this->simple_sum(b);
		result.negative = true;
		return result;
	}
	else if (negative && !b.negative) { //+
		HugeInt tmp(*this);
		tmp.negative = false;
		if (tmp.compare(b) == -1) {
			return b.simple_dif(tmp);
		}
		else if (tmp.compare(b) == 1) {
			HugeInt result;
			result = tmp.simple_dif(b);
			result.negative = true;
			return result;
		}
		else {
			HugeInt result;
			result.set("0");
			return result;
		}
	}
	else if (!negative && b.negative) { // +
		HugeInt tmp(b);
		tmp.negative = false;
		if (this->compare(tmp) == 1) {
			return this->simple_dif(b);
		}
		else if (this->compare(tmp) == -1) {
			HugeInt result;
			result = tmp.simple_dif(*this);
			result.negative = true;
			return result;
		}
		else {
			HugeInt result;
			result.set("0");
			return result;
		}
	}
}

HugeInt HugeInt::dif(HugeInt& b) {
	if (!negative && !b.negative) { // +
		if (this->compare(b) == 1) {
			return this->simple_dif(b);
		}
		else {
			HugeInt result;
			result = b.simple_dif(*this);
			result.negative = true;
			return result;
		}
	}
	else if (negative && b.negative) { 
		HugeInt tmp_this(*this);
		HugeInt tmp_b(b);
		tmp_this.negative = false;
		tmp_b.negative = false;
		if (tmp_this.compare(tmp_b) == -1) { //+
			return tmp_b.simple_dif(tmp_this);
		}
		else if (tmp_this.compare(tmp_b) == 1) {//+
			HugeInt result;
			result = tmp_this.simple_dif(tmp_b);
			result.negative = true;
			return result;
		}
		else {
			HugeInt result;
			result.set("0");
			return result;
		}
	}
	else if (negative && !b.negative) { // +
		HugeInt result;
		result = this->simple_sum(b);
		result.negative = true;
		return result;
	}
	else if (!negative && b.negative) { //  +
		return this->simple_sum(b);
	}
}