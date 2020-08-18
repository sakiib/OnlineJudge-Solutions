#include <bits/stdc++.h>

using namespace std ;

string solve( string & input ) {
	string int_part = "" ;
	string dec_part = "" ;
	string b_part = "" ;

	int st = -1 ;

	for( int i = 0 ; i < input.size() ; i ++ ) {
		if( input[ i ] == '.' ) {
			st = i + 1 ;
			break ;
		}
		int_part += input[ i ] ;
	}

	for( int i = st ; i < input.size() ; i ++ ) {
		if( input[ i ] == 'e' ) {
			st = i + 1 ;
			//dec_part += input[ i ] ;
			break ;
		}
		dec_part += input[ i ] ;
	}

	for( int i = st ; i < input.size() ; i ++ ) {
		b_part += input[ i ] ;
	}

	istringstream iss( b_part ) ;
	int num_b ;
	iss >> num_b ;

	for( int i = 0 ; i < min( num_b , (int)dec_part.size() ) ; i ++ ) {
		int_part += dec_part[ i ] ;
	}

	if( dec_part.size() == num_b ) {
		return int_part ;
	}

	if( dec_part.size() < num_b ) {
		int rem = num_b - dec_part.size() ;
		for( int i = 0 ; i < rem ; i ++ ) {
			int_part += "0" ;
		}
		return int_part ;
	}

	//int rem = dec_part.size() - num_b ;
	string rem_dec = "" ;

	for( int i = num_b ; i < dec_part.size() ; i ++ ) {
		rem_dec += dec_part[ i ] ;
	}

	if( rem_dec.size() == 1 && rem_dec[ 0 ] == '0' ) {
		return int_part ;
	}
	int_part += '.' ;
	int_part += rem_dec ;
	return int_part ;
}

string process( string input ) {
	for( int i = 0 ; i < input.size() ; i ++ ) {
		if( input[ i ] != '0' ) {
			return input.substr( i ) ;
		}
	}
}

int main() {

	string input = "" ;
	cin >> input ;
	string res = solve( input ) ;
	//res = process( res ) ;
	cout << res << endl ;

	return 0 ;
}
