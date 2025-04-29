# Tetris Game: Bài tập lớn lập trình nâng cao
# Tác giả
- Họ và tên: Nguyễn Văn Tiến
- Lớp: K69I-CS5
- Mã sinh viên: 24021641
# 🎮 Tetris – Trò chơi xếp hình kinh điển

**Tetris** là một trò chơi giải đố kinh điển, nơi người chơi phải xoay và sắp xếp các khối hình (gọi là *tetromino*) rơi xuống để tạo thành các hàng ngang hoàn chỉnh. Khi một hàng được lấp đầy, nó sẽ biến mất và người chơi sẽ ghi điểm. Trò chơi kết thúc khi các khối chất đống chạm đỉnh bảng.

Phiên bản này được lập trình bằng **C++** sử dụng thư viện **SDL2**

Video demo: [Tetris C++ with SDL2](https://youtu.be/kcqnd57YXS4)
# ⚙️ Hướng dẫn cài đặt

## 🔧 Yêu cầu

- [MSYS2](https://www.msys2.org/) (hệ thống terminal và trình quản lý gói cho Windows)
- Các thư viện SDL2 đã được bao gồm sẵn trong project

---

## 🛠️ Các bước cài đặt và chạy

#### 1️⃣ Cài đặt MSYS2
Tải từ trang chính thức: [MSY2](https://www.msys2.org)
 
 Sau khi cài xong, mở **MSYS2 UCRT64** và cài trình biên dịch:

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```
Thêm MSYS2 vào PATH
#### 2️⃣ Clone project

#### 3️⃣ Build game

```bash
mingw32-make
```



# 🎮 Hướng dẫn chơi

## 🕹️ Điều khiển

| Phím         | Tác dụng                     |
|--------------|------------------------------|
| ⬅️ / ➡️      | Di chuyển khối sang trái/phải |
| ⬆️           | Xoay khối                     |
| ⬇️           | Tăng tốc độ rơi               |
| Space        | Hard Drop        |
| C            | Hold |

## 📐 Luật chơi

- Mỗi khi một hàng ngang được lấp đầy, hàng đó sẽ biến mất và bạn được cộng điểm.
- Game kết thúc khi các khối chạm đến đỉnh bảng.

## 🎯 Mục tiêu

Giữ cho bảng không bị đầy càng lâu càng tốt và đạt điểm số cao nhất!

---

# Một số hình ảnh của game
![Image](https://private-user-images.githubusercontent.com/200005493/438812471-e8a53121-d7f3-45e5-8241-7d7b59901996.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDU5MzgzNzcsIm5iZiI6MTc0NTkzODA3NywicGF0aCI6Ii8yMDAwMDU0OTMvNDM4ODEyNDcxLWU4YTUzMTIxLWQ3ZjMtNDVlNS04MjQxLTdkN2I1OTkwMTk5Ni5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNDI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDQyOVQxNDQ3NTdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT01YjgzNzRmZmZmYWU3NmMyN2IwYmYxMWY3ZmM5OTJmYmYwYmRjMmJjZDU0YjU5NGFjZjFmNTEyMjAxYjZhM2U4JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.R5OJwOT6SB-OXcXxMTWpkghRoN7wFQWuuvEZZOQPWss)
![Image](https://private-user-images.githubusercontent.com/200005493/438812790-166d4c6f-5251-4238-91b6-e882b94d42fd.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDU5Mzg0MjEsIm5iZiI6MTc0NTkzODEyMSwicGF0aCI6Ii8yMDAwMDU0OTMvNDM4ODEyNzkwLTE2NmQ0YzZmLTUyNTEtNDIzOC05MWI2LWU4ODJiOTRkNDJmZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNDI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDQyOVQxNDQ4NDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05NzNhMjM1OGQxNDIwNWI2YzkzZDY4OTdjY2JhNjhiOWU2MTllN2M5MWY4MzgxNzdlOGM2N2ZmODQzMDhkY2I0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.Jjf10eFQYkyy0W1dqmJtm1XFbINVLTIKHr_sEv5nj-Q)

# Tài liệu tham khảo
- Tham khảo code mẫu tại [Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/index.php)

- Toàn bộ hình ảnh, âm thanh được lấy từ [Tetris](https://tetris.com/play-tetris)

- Ngoài ra, không sử dụng code ở những nguồn không được liệt kê ở trên



