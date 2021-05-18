#include "input.h"
#include "main.h"

#include <iostream>
#include <string>

using namespace std;

void nhap_account(){
    ifstream file_account(l_account);
    if(file_account.is_open()){
        while(!file_account.eof()){
            int id;
            string pass;
            int pass_2;
            int so_lan_sai_pass;
            int so_tien;
            bool khoa_tk;
            int khoa;

            file_account >> id >> pass >> pass_2 >> so_lan_sai_pass >> so_tien >> khoa;
            if(khoa==1){
                khoa_tk=true;
            }
            else{
                khoa_tk=false;
            }
            account t(id,pass,pass_2,so_lan_sai_pass, so_tien, khoa_tk);
            list_account.push_back(t);
        }
        file_account.close();
    }
    else{
        cout << "loi" << endl;
    }
}
void nhap_so_luong_tien(){
    ifstream file_money(l_money);
    if(file_money.is_open()){
        int i=0;
        while(!file_money.eof()){
            file_money >> so_to_tung_menh_gia[i];
            i++;
        }
        file_money.close();
    }
    else{
        cout << "loi" << endl;
    }
}
void tien_atm(){
    so_tien_atm=0;
    for(int i=0; i<9; i++){
        so_tien_atm += so_to_tung_menh_gia[i]*menh_gia[i];
    }
}
