#ifndef __MFILE_H__
#define __MFILE_H__

//
// TODO: Viết hàm đóng gói các công việc cần làm để ghi dữ liệu vào file
//
// Giả sử dữ liệu chỉ cần đọc viết 1 lần lần (kích thước của buf đủ để chứa toàn bộ dữ
// liệu đọc từ file)
void write2File(const char fname[], const data_t buf[], const int n);

//
// TODO: Viết hàm đóng gói các công việc cần làm để đọc dữ liệu từ file
// Trả về số phần tử đọc được
// Dữ liệu được chứa trong buf, buf phải được cấp phát trước ngoài hàm
int readFromFile(const char fn[], data_t buf[], int elemSize);

#endif