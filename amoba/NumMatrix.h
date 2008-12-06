/*
 * NumMatrix.h
 *
 *  Created on: 2008.12.05.
 *      Author: bacsog
 */

#ifndef NUMMATRIX_H_
#define NUMMATRIX_H_

#define SIZE 15

#include <iostream>
#include <sstream>
#include <string>

template<class T> class NumMatrix {
public:
	NumMatrix<T> () {
		data = new T[SIZE * SIZE]();
		for (int i = 0; i < SIZE * SIZE; i++) {
			data[i] = 0;
		}
	}
	virtual ~NumMatrix<T> () {
		delete[] data;
	}

	void print() {
		std::cout << "\n**********START**********\n";
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				std::cout << data[i * SIZE + j];
			}
			std::cout << "\n";
		}
		std::cout << "***********END***********\n";
		std::cout.flush();
	}

	int getCell(int a, int b) {
		if (a >= 0 && a < SIZE && b >= 0 && b < SIZE) {
			return data[a * SIZE + b];
		} else {
			return -1;
		}
	}

	void setCell(int a, int b, T value) {
		if (a >= 0 && a < SIZE && b >= 0 && b < SIZE) {
			data[a * SIZE + b] = value;
		}
	}

	int getSize() {
		return SIZE;
	}

	std::string getHash() {
		std::stringstream ss;
		std::stringstream temp_ss;
		temp_ss << "";
		bool start = false;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (getCell(i, j) != 0) {
					if (!start) {
						ss << (i * SIZE + j);
						ss << "-";
						ss << getCell(i, j);
						start = true;
					} else {
						ss << temp_ss.str();
						ss << getCell(i, j);
						temp_ss.str("");
					}
				} else if (start) {
					temp_ss << getCell(i, j);
				}
			}

		}
		return ss.str();
	}

private:
	T* data;

};

#endif /* NUMMATRIX_H_ */
