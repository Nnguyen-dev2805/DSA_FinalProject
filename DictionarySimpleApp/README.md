# TỪ ĐIỂN ANH-VIỆT VỚI TÍNH NĂNG AUTOCOMPLETE VÀ AUTOCORRECT

## Mục lục
1. [Mô tả dự án](#mô-tả-dự-án)
2. [Tính năng chính](#tính-năng-chính)
3. [Cấu trúc dự án](#cấu-trúc-dự-án)
4. [Hướng dẫn sử dụng](#hướng-dẫn-sử-dụng)
5. [Công nghệ sử dụng](#công-nghệ-sử-dụng)
6. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt)
7. [Video demo](#video-demo)
8. [Đóng góp](#đóng-góp)
9. [Tác giả](#tác-giả)

## Mô tả dự án
Dự án này là một ứng dụng từ điển Anh-Việt được xây dựng bằng ngôn ngữ lập trình C++. Ứng dụng cung cấp các tính năng như tìm kiếm từ, tự động hoàn thành (autocomplete), tự động sửa lỗi (autocorrect), và quản lý danh sách từ yêu thích (bookmarks). 

Dự án sử dụng các cấu trúc dữ liệu và thuật toán như:
- **Trie**: Được sử dụng để triển khai tính năng autocomplete và autocorrect.
- **Hash Table**: Được sử dụng để lưu trữ và tìm kiếm nhanh các từ và định nghĩa.
- **Danh sách liên kết (Linked List)**: Được sử dụng để quản lý danh sách từ yêu thích (bookmarks).

## Tính năng chính
1. **Tìm kiếm từ**:
   - Người dùng có thể nhập từ cần tìm kiếm.
   - Nếu từ không tồn tại, hệ thống sẽ gợi ý các từ gần đúng hoặc tương tự.

2. **Tự động hoàn thành (Autocomplete)**:
   - Khi người dùng nhập một phần của từ, hệ thống sẽ gợi ý các từ hoàn chỉnh bắt đầu bằng phần đã nhập.

3. **Tự động sửa lỗi (Autocorrect)**:
   - Nếu người dùng nhập sai chính tả, hệ thống sẽ gợi ý các từ gần đúng.

4. **Quản lý danh sách yêu thích (Bookmarks)**:
   - Người dùng có thể thêm từ vào danh sách yêu thích.
   - Hiển thị danh sách các từ đã lưu.

5. **Tải dữ liệu từ file**:
   - Dữ liệu từ điển được tải từ file văn bản (`EnglishDictionary.txt`) hoặc file nhị phân (`EnglishDictionary.dat`).

## Cấu trúc dự án
### Các file chính
1. **`main.cpp`**:
   - Điểm bắt đầu của chương trình.
   - Tạo đối tượng giao diện người dùng (UI) và xử lý luồng chính của ứng dụng.

2. **`UI.h`**:
   - Quản lý giao diện người dùng.
   - Hiển thị menu, xử lý nhập liệu từ bàn phím, và điều hướng giữa các màn hình.

3. **`Trie.h`**:
   - Triển khai cấu trúc dữ liệu Trie.
   - Cung cấp các chức năng như thêm từ, tìm kiếm từ, và gợi ý từ dựa trên tiền tố.

4. **`TrieNode.h`**:
   - Định nghĩa cấu trúc của một nút trong Trie.

5. **`HashTable.h`**:
   - Triển khai bảng băm (Hash Table) để lưu trữ và tìm kiếm từ điển.
   - Sử dụng hàm băm để ánh xạ từ vào các chỉ mục trong bảng.

6. **`Bookmark.h`**:
   - Quản lý danh sách từ yêu thích bằng danh sách liên kết.
   - Cung cấp các chức năng như thêm từ, kiểm tra từ đã tồn tại, và hiển thị danh sách.

7. **`generateFileBinary.cpp`**:
   - Chuyển đổi dữ liệu từ file văn bản (`EnglishDictionary.txt`) sang file nhị phân (`EnglishDictionary.dat`) để tối ưu hóa việc đọc dữ liệu.

### Thư mục dữ liệu
- **`InputFile/EnglishDictionary.txt`**: File chứa dữ liệu từ điển dưới dạng văn bản.
- **`InputFile/EnglishDictionary.dat`**: File chứa dữ liệu từ điển dưới dạng nhị phân.
- **`InputFile/Bookmark.txt`**: File lưu danh sách từ yêu thích.

## Hướng dẫn sử dụng
1. **Chạy chương trình**:
   - Biên dịch và chạy file `main.cpp`.
   - Giao diện chính sẽ hiển thị các tùy chọn:
     - Tìm kiếm từ.
     - Quản lý danh sách yêu thích.
     - Thoát chương trình.

2. **Tìm kiếm từ**:
   - Chọn "Search for a word" từ menu chính.
   - Nhập từ cần tìm kiếm.
   - Hệ thống sẽ hiển thị định nghĩa hoặc gợi ý từ gần đúng.

3. **Thêm từ vào danh sách yêu thích**:
   - Sau khi tìm kiếm từ, nhấn phím `B` để thêm từ vào danh sách yêu thích.

4. **Xem danh sách yêu thích**:
   - Chọn "Bookmarks" từ menu chính để xem danh sách các từ đã lưu.

5. **Thoát chương trình**:
   - Chọn "Exit" từ menu chính và xác nhận để thoát.

## Công nghệ sử dụng
- Ngôn ngữ lập trình: **C++**
- Cấu trúc dữ liệu: **Trie**, **Hash Table**, **Linked List**
- File I/O: Đọc và ghi dữ liệu từ file văn bản và file nhị phân.

## Hướng dẫn cài đặt
1. Clone repository:
   ```bash
   git clone git@github.com:Nnguyen-dev2805/DSA_Dictionary_English_Vietnamese_NN.git
   ```
- Mở dự án trong IDE hỗ trợ C++ (Visual Studio, Code::Blocks, v.v.).
- Biên dịch và chạy file `main.cpp`.

## Video demo
Xem video demo tại đây: [YouTube Demo](https://www.youtube.com/watch?v=dhYQ9jI3_4Q)

## Đóng góp
Nếu bạn muốn đóng góp cho dự án, vui lòng tạo một pull request hoặc mở một issue trên GitHub.

## Tác giả
Mã số sinh viên: 23110273     
Họ và tên: Trương Nhất Nguyên
