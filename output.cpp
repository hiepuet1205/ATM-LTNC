#include "output.h"
#include "main.h"

#include <iostream>
#include <string>

void cap_nhat_account(){
    ofstream file_account(l_account);

    if(file_account.is_open()){
        for(int i=0; i<list_account.size(); i++){
            int khoa;
            if(list_account[i].khoa_tk==false){
                khoa=1;
            }
            else{
                khoa=0;
            }
            file_account << list_account[i].id << " " << list_account[i].pass << " " << list_account[i].pass_2 << " " << list_account[i].so_lan_sai_pass
            << " " << list_account[i].so_tien << " " << khoa << endl;
        }
        file_account.close();
    }
    else{
        cout << "loi" << endl;
    }
}
void cap_nhat_so_luong_tien(){
    ofstream file_money(l_money);
    if(file_money.is_open()){
        for(int i=0; i<9; i++){
            file_money << so_to_tung_menh_gia[i] << " ";
        }
        file_money << endl;
        file_money.close();
    }
    else{
        cout << "loi" << endl;
    }
}

void cap_nhat_his(account& a, int trang_thai, int id, int so_tien){
    string file = to_string(a.id) + ".txt";
    string file1 = to_string(id) + ".txt";
    ofstream his(file, ios::out | ios::app);
    if(his.is_open()){
        his << endl;
        his << trang_thai << " " << id << " " << so_tien;
        his.close();
    }
    else{
        cout << "loi" ;
    }

    if(trang_thai==3){
        ofstream his1(file1, ios::out | ios::app);
        cout << 10;
        if(his1.is_open()){
            his1 << endl;
            his1 << trang_thai+1 << " " << a.id << " " << so_tien;
            his1.close();
        }
        else{
            cout << "loi" ;
        }
    }
}


