/*************************************************************************
  > File Name: Seqlist.h
  > Author: dengbaole
  > Mail: 1550555930@qq.com 
  > Created Time: 2022年07月06日 星期三 12时51分15秒
 ************************************************************************/

#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <stdio.h>

#define N 100
typedefine int 


struct Seqlist
{
	int a[]; 
	//表示数据存储的大小
	int size;
	int ability;
};





#endif
