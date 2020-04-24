#ifndef __cplusplus
	//#pragma message("Implementation is NOT Standards Compliant!")
#else
	#if __cplusplus >= 201703l
		//#pragma message("Implementation is C++17 Compliant.")
	#elif __cplusplus >= 201402l
		//#pragma message("Implementation is C++14 Compliant.")
	#elif __cplusplus >= 201103l
		//#pragma message("Implementation is C++11 Compliant.")
	#elif __cplusplus >= 199711l
		//#pragma message("Implementation is C++03 Compliant.")
	#else
		//#pragma message("Unknown Standard!")
	#endif
#endif

#ifndef __STDCPP_STRICT_POINTER_SAFETY__
	//#pragma message("Implementation does NOT Have Strict Pointer Safety!")
#endif

#ifndef __STDCPP_THREADS__
	//#pragma message("Program does NOT Run Mulptiplr Threads!")
#endif

#ifndef __STDC_MB_MIGHT_NEQ_WC__
	//#pragma message("Character Literals in the Base Character Set may Have the Same Value in char and wchar_t!")
#endif 

#ifndef __STDCPP_DEFAULT_NEW_ALIGNMENT__
	//#pragma message("NO Default Alignment Value!")
#endif

#ifndef  __STDC_HOSTED__
	//#pragma message("Implementation is Free Standing!")
#endif

#ifndef __STDC_ISO_10646__
	//#pragma message("wchar_t is NOT Encoded as Unicode!")
#endif

#ifdef _MSC_VER
	#ifdef _CONTROL_FLOW_GUARD
	#endif

	#ifdef _CPPRTTI
	#endif

	#ifdef _CPPUNWIND
	#endif

	#ifdef _MT
	#endif

	#ifdef _DLL
	#endif

	#ifdef _M_AMD64
	#endif

	#ifdef _M_IX86
	#endif

	#ifdef _M_X64
	#endif

	#ifdef _M_ARM
	#endif

	#ifdef _M_ARM64
	#endif

	#ifdef _M_FP_EXCEPT
	#endif

	#ifdef _M_FP_FAST
	#endif

	#ifdef _M_FP_PRECISE
	#endif

	#ifdef _M_FP_STRICT
	#endif

	#ifdef __MSVC_RUNTIME_CHECKS
	#endif

	#ifdef _WCHAR_T_DEFINED
	#endif

	#ifdef _WIN32
	#endif

	#ifdef _WIN64
	#endif
#endif

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template<typename T = uint32_t>
void createOddMagicSquare(vector<vector<T>>& square) noexcept(false){
	const size_t	square_size(square.size());
	const T			casted_size(static_cast<T>(square_size));

	size_t	column_index(square_size - 1);
	size_t	row_index(square_size / 2);
	T		number(0);

	for(size_t column_cnt(0); column_cnt != square_size; ++column_cnt){
		for(size_t row_cnt(0); row_cnt != square_size; ++row_cnt){
			square[column_index][row_index] = number;
			++number;
			column_index = (column_index + 1) % casted_size;
			row_index = (row_index + 1) % casted_size;
		}
		column_index = (column_index + casted_size - 2) % square_size;
		row_index = (row_index + square_size - 1) % square_size;
	}

	return;
}

template<typename T = uint32_t>
void createDoublyEvenMagicSquare(vector<vector<T>>& square) noexcept(false){
	//TODO:
	cerr << "Sorry, The Implementation of Magic Square Consrtuction for Doubly Even Order is NOT Done yet..." << endl;
	return;
}

template<typename T = uint32_t>
void createSignlyEvenMagicSquare(vector<vector<T>>& square) noexcept(false){
	//TODO: LUX Method
	cerr << "Sorry, The Implementation of Magic Square Consrtuction for Doubly Even Order is NOT Done yet..." << endl;
	return;
}

template<typename T = uint32_t>
void createMagicSquare(vector<vector<T>>& square) noexcept(false){
	const size_t square_size = square.size();
	if(square_size == 0 || square_size == 2){
		cerr << "A Nontrivial Magic Square CANNOT be Constructed with This Square Size..." << endl;
		return;
	}

	//Odd Number
	if(square_size % 2 == 1){
		createOddMagicSquare(square);
	}
	//Doubly Even Number
	else if(square_size % 4 == 0){
		createDoublyEvenMagicSquare(square);
	}
	//Singly Even Number
	else{
		createSignlyEvenMagicSquare(square);
	}

	return;
}

const int main(const int argc, const char* const* const argv){
#ifdef _DEBUG
	cout << "Command Line Argument(" << argc << "): "  << endl;
	for(size_t i(0), end(static_cast<size_t>(argc)); i < end; ++i){
		cout << "    " << argv[i] << endl;
	}
	cout << "Compiled on " << __DATE__ << ", " << __TIME__ << endl;
#endif
	
	vector<vector<uint32_t>> magic_square;
	size_t square_size(0);

	//Input Square Size
	cout << "Input Magic Square Size: ";
	cin >> square_size;

	//Resize Square
	magic_square.resize(square_size);
	for(auto& it : magic_square){
		it.resize(square_size, 0);
	}

	createMagicSquare(magic_square);

	size_t max_digit = static_cast<size_t>(floor(log10(square_size * square_size) + 1));

	cout << "Result:" << endl;
	for(const auto& it_column : magic_square){
		for(const auto& it_row : it_column){
			cout << setw(max_digit + 1) << it_row << " ";
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}