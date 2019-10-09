#ifndef _CLUSTER_HPP
#define _CLUSTER_HPP

#include <iostream>
#include <array>
template<typename T, int N>
class cluster{
private:
	std::array<T, N> typeArray = {};
public:
	void add( T addType ){
		if(contains( addType )==0){
			for( int i = 0; i<N;i++){
				if(typeArray[i] == T()){
					typeArray[i] = addType;
					break;
				}
			}
		}	
	} 
	void remove( T removeType ){
		for( int i = 0; i<N;i++){
			if(typeArray[i] == removeType){
				for( int j = i; j<N-1; j++){
					typeArray[j] = typeArray[j+1];
				}
				typeArray[N-1] = T();
				
			}
		}
	}
	bool contains( T containsType ){
		for( int i = 0; i<N;i++){
			if( typeArray[i] == containsType ){
				return 1;
			}		
		}
		return 0;
	}
	friend std::ostream& operator<<( std::ostream & stream, const cluster & set ){
		for( const auto & i : set.typeArray ){
			stream << i << ", ";
		}
		return stream;
	}

};

#endif //_CLUSTER_HPP