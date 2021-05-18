#ifndef main__H_
#define main__H_

#include <string>
#include <vector>
#include "function.h"

using namespace std;

extern int id;
extern string pass;

const char l_account[]="account.txt";
const char l_money[]="money.txt";

const int menh_gia[9] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};
extern int so_to_tung_menh_gia[9] ;
extern int so_tien_atm ;

extern int login_thanh_cong ;

extern int tuy_chon;
extern int temp;

extern vector<account> list_account;

#endif // main__H_
