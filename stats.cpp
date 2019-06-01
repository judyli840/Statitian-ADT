// stats.cpp - implements statistician class as defined in stats.h
// JUDY LI, 1/23
  
#include <cassert>  // provides assert
#include "stats.h"  // defines what mus 

    statistician::statistician(){
        len = 0;
        summ = 0;
        last = 0;
        smallest = 0;
        largest = 0;
    }

    void statistician::next(double r){
        summ += r;
        len++;
        
        if (len==1){
           smallest = r;
	   largest = r;
        }else if (smallest >  r){
		smallest = r;
	}else if(largest < r){
          largest = r;
        }

        last = r;
    }

    void statistician::reset(){
        len = 0;
        summ = 0;
        last = 0;
        smallest = 0;
        largest = 0;
    }

    int statistician::length() const{
        return len;
    }

    double statistician::sum() const{
        return summ;
    }
    
    double statistician::mean() const{
        assert(len>0);
        return (summ/len);
    }

    double statistician::minimum() const{
        assert(length()>0);
        return smallest;
    }

    double statistician::maximum() const{
        assert(length()>0);
        return largest;
    }

    statistician operator +(const statistician& s1, const statistician& s2){
        statistician temp;
	temp.len = s1.len + s2.len;
	temp.summ = s1.summ + s2.summ;

	if (s1.len == 0 && s2.len == 0){
		return temp;
	}else if (s1.len == 0){
		temp.smallest = s2.smallest;
		temp.largest = s2.largest;
	}else if (s2.len == 0){
		temp.smallest = s1.smallest;
		temp.largest = s1.largest;
	}

       if (s1.len > 0 && s2.len >0){
	       if(s1.smallest > s2.smallest)
		       temp.smallest = s2.smallest;
	       else
		       temp.smallest = s1.smallest;
	       if (s1.largest > s2.largest)
		       temp.largest = s1.largest;
	       else
		       temp.largest = s2.largest;
       }


        return temp;
    }

    statistician operator *(double scale, const statistician& s){
	if (s.len == 0){
		return s;
	}

        statistician temp;
        temp.len = s.len;
        temp.summ = scale * s.summ;

	if (scale<0){
		temp.largest = scale * s.smallest;
		temp.smallest  = scale * s.largest;
	}else{
		temp.largest = scale * s.largest;
		temp.smallest = scale * s.smallest;
    }


        return temp;
    }

    bool operator ==(const statistician& s1, const statistician& s2){
        if ((s1.length()==0) && (s2.length()==0))
            return true;
        else
            return ((s1.length() == s2.length()) && (s1.mean() == s2.mean()) && 
                (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()) 
                && (s1.sum() == s2.sum()));
        
    }
