#include "crud.h"

int show_menu(){
    while(true){
        std::cout << "****************************" << std::endl;
        std::cout << "*       ͼ�����ϵͳ          *" << std::endl;
        std::cout << "* 1����ʾ����ͼ����Ϣ          *" << std::endl;
        std::cout << "* 2�����ͼ����Ϣ             *" << std::endl;
        std::cout << "* 3���޸�ͼ����Ϣ             *" << std::endl;
        std::cout << "* 4��ɾ��ͼ����Ϣ             *" << std::endl;
        std::cout << "* 5����ѯͼ����Ϣ             *" << std::endl;
        std::cout << "* 0���˳�ϵͳ                *" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "��ѡ��: " << std::endl;
        int choice = 0;
        std::cin >> choice;
        if (choice >= 0 && choice <= 5){
            return choice;
        }
        else{
            std::cout << "�����������������" << std::endl;
            std::cin.get();
            continue;
        }
    }
}

// ��ʾ����ͼ����Ϣ
void show_book(MYSQL& mysql){
    MYSQL_RES *result;
    MYSQL_ROW row;
    mysql_query(&mysql, "set names gbk"); //���ñ����ʽ ������������
    // 1��ִ��ʧ�� 0��ִ�гɹ�
    if(mysql_query(&mysql, "select * from tb_book")){
        std::cout << "��ѯʧ��" << std::endl;
        std::cout << "�������: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        std::cout << "------ͼ����Ϣ------" << std::endl;
        result = mysql_store_result(&mysql);
        if (mysql_num_rows(result)){
            while((row = mysql_fetch_row(result))){
                std::cout << row[0] << "\t" << row[1] << "\t";
                std::cout << row[2] << "\t" << row[3] << std::endl;
            }
        }
        else{
            std::cout << "û�м�¼" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// ���ͼ��
void add_book(MYSQL& mysql){
    std::cout << "------���ͼ����Ϣ------" << std::endl;
    MYSQL_RES *result;
    std::string book_name, author, book_concern;
    std::string sql = "select * from tb_book where book_name='";
    std::string sql2 = "insert into tb_book (book_name, author, book_concern) value (";
    // �����һ������ʱ��������\n
    std::cin.ignore(100, '\n');
    std::cout << "������������";
    std::getline(std::cin, book_name);

    std::cout << "���������ߣ�";
    std::getline(std::cin, author);

    std::cout << "����������磺";
    std::getline(std::cin, book_concern);

    sql += book_name + "' && author='" + author + "' && book_concern='" + book_concern + "'";
    mysql_query(&mysql, "set names gbk");
    //mysql_query�ڶ�������ֻ����const char* ���������ת��
    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "��ѯʧ��" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "�������: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        result = mysql_store_result(&mysql);
        std::cout << "result = " << result << std::endl;
        unsigned long long int row = mysql_num_rows(result);
        // ���м�¼
        if (row > 0){
            std::cout << "���ݿ������иü�¼����������" << std::endl;
            sql2 += "'" + book_name + "', '" + author + "', '" + book_concern + "')";
            if(mysql_query(&mysql, sql2.c_str())){
                std::cout << "��������ʧ��" << std::endl;
                std::cout << sql2 << std::endl;
                std::cout << "�������: " << mysql_errno(&mysql) << std::endl;
                system("pause");
                return;
            }
            else {
                std::cout << "�������ݳɹ�" << std::endl;
                return;
            }
        }
        // û�м�¼���²�������
        else{
            sql2 += "'" + book_name + "', '" + author + "', '" + book_concern + "')";
            if(mysql_query(&mysql, sql2.c_str())){
                std::cout << "��������ʧ��" << std::endl;
                std::cout << sql2 << std::endl;
                std::cout << "�������: " << mysql_errno(&mysql) << std::endl;
                system("pause");
                return;
            }
            else{
                std::cout << "�������ݳɹ�" << std::endl;
                return;
            }
        }
    }
}

// �޸�ͼ����Ϣ
void modify_book(MYSQL& mysql){
    std::cout << "------�޸�ͼ����Ϣ------" << std::endl;
    MYSQL_RES *result;
    MYSQL_ROW row;
    std::string book_name, author, book_concern;
    std::string sql = "select * from tb_book where ID=";
    std::string sql2 = "update from tb_book set book_name='";
    std::string ID;

    // �����һ������ʱ��������\n
    std::cin.ignore(100, '\n');

    while(true){
        puts("������ID��");
        std::getline(std::cin, ID);
        if(!is_all_digit(ID)){
            std::cout << "������������������" << std::endl;
            continue;
        }
        else break;
    }

    sql += ID;
    mysql_query(&mysql, "set names gbk");
    //mysql_query�ڶ�������ֻ����const char* ���������ת��
    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "��ѯʧ��" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "�������: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        result = mysql_store_result(&mysql);
        if (mysql_num_rows(result)){
            std::cout << "IDΪ " << ID << " ������Ϣ����:" << std::endl;
            while((row = mysql_fetch_row(result))){
                std::cout << row[0] << "\t" << row[1] << "\t";
                std::cout << row[2] << "\t" << row[3] << std::endl;
            }
            std::cout << "�������µ���Ϣ��" << std::endl;
            std::cout << "������";
            std::getline(std::cin, book_name);

            std::cout << "���ߣ�";
            std::getline(std::cin, author);

            std::cout << "�����磺";
            std::getline(std::cin, book_concern);
        }
        else{
            std::cout << "���޴���" << std::endl;
            return;
        }
    }
    system("pause");
    system("cls");
}

// ɾ��ͼ��
void delete_book(MYSQL& mysql){

}

// ��ѯͼ��
void query_book(MYSQL& mysql){

}

bool input_check(const std::string& str, int size){

}

bool is_all_digit(const std::string& str){
    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}


