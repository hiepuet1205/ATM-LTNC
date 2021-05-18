#include "function.h"
#include "main.h"
#include "output.h"
#include "input.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

bool check_pass(string pass, string pass_temp){
    if(pass_temp==pass)
        return true;
    return false;
}
bool check_khoa_tk(account a){
    if(a.so_lan_sai_pass >=5)
        return true;
    return false;
}
bool check_tien_rut(int so_tien_rut, int so_tien_atm){
    if(so_tien_rut > so_tien_atm)
        return false;
    return true;
}

void xu_ly_login_tk(){
    bool check_id=false;
    for(int i=0; i<list_account.size(); i++){
        if(id==list_account[i].id){
            check_id = true;
            if(check_khoa_tk(list_account[i])){
                list_account[i].khoa_tk=true;
                system("cls");
                cout << "Tai khoan cua ban da bi khoa." << endl;
            }
            else{
                if(check_pass(list_account[i].pass,pass)){
                    list_account[i].so_lan_sai_pass = 0;
                    system("cls");
                    cout << "Dang nhap thanh cong" << endl;
                    Sleep(1000);
                    system("cls");
                    login_thanh_cong = 1;
                    temp = i;
                }
                else{
                    list_account[i].so_lan_sai_pass++;
                    system("cls");
                    cout << "Mat khau sai." << endl;
                    cout << "So lan sai mat khau(5 lan khoa mom): " << list_account[i].so_lan_sai_pass << endl;
                    Sleep(2000);
                    system("cls");
                    login_thanh_cong = 0;
                }
            }
            break;
        }
    }
    if(!check_id){
        cout << "id khong ton tai" << endl;
        login_thanh_cong = 0;
    }
    cap_nhat_account();
}
void login(){
    while(login_thanh_cong==0){
        cout << "Nhap tk cua ban: " << endl;
        cout << "Id: " ;
        cin >> id;
        cout << "Pass: " ;
        cin >> pass;
        xu_ly_login_tk();
    }
}

void menu(account& a){
    if(login_thanh_cong==1){
        cout << "Menu: " << endl;
        cout << "1 - Kiem tra tai khoan." << endl;
        cout << "2 - Rut tien." << endl;
        cout << "3 - Gui tien." << endl;
        cout << "4 - Chuyen tien." << endl;
        cout << "5 - Doi pass." << endl;
        cout << "6 - Kiem tra lich su giao dich." << endl;
        cout << "7 - Dang xuat." << endl;

        cin >> tuy_chon;
        switch (tuy_chon){
        case 1:
            {
                check_tien(a);
                cout << "0 - Quay lai menu." << endl;
                cin >> tuy_chon;
                system("cls");
                Sleep(500);
                menu(a);
                break;
            }
        case 2:
            {
                rut_tien(a);
                cout << "0 - Quay lai menu." << endl;
                cin >> tuy_chon;
                system("cls");
                Sleep(500);
                menu(a);
                break;
            }
        case 3:
            {
                gui_tien(a);
                cout << "0 - Quay lai menu." << endl;
                cin >> tuy_chon;
                system("cls");
                Sleep(500);
                menu(a);
                break;
            }
        case 4:
            {
                chuyen_tien(a);
                cout << "0 - Quay lai menu." << endl;
                cin >> tuy_chon;
                system("cls");
                Sleep(500);
                menu(a);
                break;
            }
        case 5:
            {
                doi_pass(a);
                login_thanh_cong=0;
                system("cls");
                Sleep(500);
                login();
                menu(a);
                break;
            }
        case 6:
            {
                kiem_tra_lich_su(a);
                cout << "0 - Quay lai menu." << endl;
                cin >> tuy_chon;
                system("cls");
                Sleep(1000);
                menu(a);
                break;
            }
        case 7:
            {
                login_thanh_cong=0;
                system("cls");
                Sleep(1000);
                login();
                menu(a);
                break;
            }
        }
    }
}

void check_tien(account a){
    system("cls");
    Sleep(500);
    cout << "Tai khoan cua ban co: " << a.so_tien << endl;
}

void xu_ly_rut_tien(account& a, int so_tien_rut){
    int so_to_tien_nhan_duoc[9];

    int temp = so_tien_rut;

    for(int i=0; i<9; i++){
        so_to_tien_nhan_duoc[i] = so_tien_rut/menh_gia[i];
        if(so_to_tung_menh_gia[i]<so_to_tien_nhan_duoc[i]){
            so_to_tien_nhan_duoc[i] = so_to_tung_menh_gia[i];
            so_to_tung_menh_gia[i]=0;
        }
        so_tien_rut = so_tien_rut - menh_gia[i]*so_to_tien_nhan_duoc[i];
        so_to_tung_menh_gia[i] -= so_to_tien_nhan_duoc[i];
    }

    if(so_tien_rut>0){
        cout << "Atm khong du tien";
    }
    else{
        system("cls");
        Sleep(500);
        cout << "Ban nhan duoc: " << endl;

        for(int i=0; i<9; i++){
            cout << "So to menh gia " << menh_gia[i] << ": " << so_to_tien_nhan_duoc[i] << endl;
        }
        a.so_tien -= temp;
        cap_nhat_so_luong_tien();
        cap_nhat_account();
        tien_atm();
        cap_nhat_his(a,1,a.id,temp);
    }
}
void rut_tien(account& a){
    int min_rut=50000, max_rut=5000000, so_tien_rut=0;
    system("cls");
    Sleep(500);
    cout << "so tien rut toi thieu: " << min_rut << endl;
    cout << "so tien rut toi da: " << max_rut << endl;
    cout << "so tien ban muon rut: " ;
    cin >> so_tien_rut;
    while(so_tien_rut<min_rut || so_tien_rut >max_rut){
        so_tien_rut=0;
        system("cls");
        Sleep(500);
        cout << "So tien rut khong hop le. Xin nhap lai so tien ban muon rut: " ;
        cin >> so_tien_rut;
    }

    while(!check_tien_rut(so_tien_rut,so_tien_atm)){
        so_tien_rut=0;
        system("cls");
        Sleep(500);
        cout << "Atm khong du tien. Xin nhap lai so tien ban muon rut: " ;
        cin >> so_tien_rut;
    }

    xu_ly_rut_tien(a, so_tien_rut);
}

void xu_ly_gui_tien(account& a, int& so_tien_gui){
    for(int i=0; i<9; i++){
        cout << "So to menh gia " << menh_gia[i] << ": ";
        int temp;
        cin >> temp;
        so_tien_gui = so_tien_gui + temp*menh_gia[i];
        so_to_tung_menh_gia[i] += temp;
    }
    cout << "So tien gui: " << so_tien_gui << endl;
    a.so_tien += so_tien_gui;
    cap_nhat_so_luong_tien();
    cap_nhat_account();
    tien_atm();
    cap_nhat_his(a,2,a.id,so_tien_gui);
}
void gui_tien(account& a){
    system("cls");
    int min_gui=500000, max_gui=50000000, so_tien_gui=0;
    cout << "so tien gui toi thieu: " << min_gui << endl;
    cout << "so tien gui toi da: " << max_gui << endl;
    xu_ly_gui_tien(a, so_tien_gui);

    while(so_tien_gui<min_gui || so_tien_gui >max_gui){
        so_tien_gui=0;
        cout << "so tien gui khong hop le. Xin nhap lai so tien ban muon gui: " << endl;
        xu_ly_gui_tien(a, so_tien_gui);
    }
}

void xu_ly_chuyen_tien(account& nguoi_gui, account& nguoi_nhan){
    bool ctien = false;
    int tien_chuyen, chuyen_max=50000000, chuyen_min= 500000;
    while(!ctien){
        system("cls");
        Sleep(500);
        cout << "So tien chuyen toi da: " << chuyen_max << endl;
        cout << "So tien chuyen toi thieu: " << chuyen_min << endl;
        cout << "Phi dich vu la 2%."<< endl;
        cout << "Nhap so tien ban muon chuyen: ";
        cin >> tien_chuyen;
        if(nguoi_gui.so_tien>tien_chuyen && tien_chuyen>=chuyen_min && tien_chuyen<=chuyen_max){
            ctien=true;
            nguoi_gui.so_tien-=tien_chuyen;
            nguoi_nhan.so_tien+=tien_chuyen*98/100;
            so_tien_atm += tien_chuyen*2/100;
            system("cls");
            cout << "Chuyen tien thanh cong." << endl;
            cap_nhat_his(nguoi_gui,3,nguoi_nhan.id,tien_chuyen);
            Sleep(500);
        }
        else{
            system("cls");
            cout << "So tien chuyen khong hop le." << endl;
            Sleep(500);
        }
    }
    cap_nhat_account();
}
void chuyen_tien(account& a){
    bool check = false, check_id=false;;
    int id, pass_2, tien_chuyen;
    while(!check){
        system("cls");
        Sleep(1000);
        cout << "Nhap pass cap 2 de xac nhan: ";
        cin >> pass_2;
        if(pass_2 == a.pass_2){
            check=true;
            system("cls");
            Sleep(500);
            cout << "Xac nhan thanh cong." << endl;
            Sleep(500);
            while(!check_id){
                system("cls");
                Sleep(1000);
                cout << "Nhap id nguoi nhan: ";
                cin >> id;
                for(int i=0; i<list_account.size(); i++){
                    if(id==list_account[i].id){
                        check_id = true;
                        xu_ly_chuyen_tien(a,list_account[i]);
                        break;
                    }
                }
                if(!check_id){
                    system("cls");
                    Sleep(500);
                    cout << "ID nguoi nhan khong ton tai." << endl;
                }
            }
        }
        else{
            cout << "Sai pass cap 2.";
        }
    }
}

void kiem_tra_lich_su(account& a){
    system("cls");
    string file = to_string(a.id) + ".txt";
    ifstream his(file.c_str());
    if(his.is_open()){
        while(!his.eof()){
            int trang_thai;
            int id;
            int so_tien;

            his >> trang_thai >> id >> so_tien ;

            if(trang_thai==1){
                cout << "Ban da rut: " << so_tien << " dong." << endl;
            }
            if(trang_thai==2){
                cout << "Ban da gui: " << so_tien << " dong." << endl;
            }
            if(trang_thai==3){
                cout << "Ban da chuyen: " << so_tien  << " dong cho tai khoan co id: " << id << "." << endl;
            }
            if(trang_thai==4){
                cout << "Tai khoan co id: " << id << " da chuyen cho ban so tien la: " << so_tien << "." << endl;
            }
        }
        his.close();
    }
    else{
        cout << "loi" ;
    }
}

void doi_pass(account& a){
    system("cls");
    string pass_cu, pass_moi1, pass_moi2;
    bool check_doi_pass=false;
    while(!check_doi_pass && !check_khoa_tk(a)){
        cout << "Mat khau cu: " ;
        cin >> pass_cu;
        if(pass_cu==a.pass){
            cout << "Mat khau moi: ";
            cin >> pass_moi1;
            cout << "Xac nhan lai mat khau: ";
            cin >> pass_moi2;
            if(pass_moi1 == pass_moi2){
                a.pass = pass_moi1;
                cout << "Doi mat khau thanh cong." << endl;
                check_doi_pass=true;
            }
            else{
                cout << "Xac nhan that bai." << endl;
            }
        }
        else{
            a.so_lan_sai_pass++;
            cout << "Mat khau sai." << endl;
            cout << "So lan sai mat khau(5 lan khoa mom): " << a.so_lan_sai_pass << endl;
        }
    }

    if(check_khoa_tk(a)){
        cout << "Tai khoan cua ban da bi khoa." << endl;
    }
    cap_nhat_account();
}
