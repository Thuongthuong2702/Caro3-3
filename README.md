# Tic Tac Toe / Caro 3x3 Game
Tác giả: Nguyễn Thị Thương 

MSV: 23021734 

Một dự án game Caro 3x3 được phát triển bằng Unity với hai chế độ chơi:
 Player vs Player
 Player vs AI

Phiên bản hiện tại sử dụng thuật toán Minimax giúp AI đưa ra nước đi tối ưu nhằm tăng khả năng chiến thắng.

---

# Giới thiệu

Cờ Caro (Tic Tac Toe) là trò chơi chiến thuật dành cho hai người chơi trên bảng 3x3.  
Người chơi lần lượt đánh dấu ký hiệu `X` hoặc `O` vào các ô trống trên bàn cờ.

Mục tiêu:
- Tạo thành một hàng gồm 3 ký hiệu giống nhau theo:
  - Hàng ngang
  - Hàng dọc
  - Đường chéo

Nếu toàn bộ bàn cờ đã được điền mà không có người chiến thắng, trò chơi sẽ kết thúc với kết quả hòa.

---
# Tính năng chính

## Chế độ 2 người chơi
- Hai người chơi thay phiên đánh dấu `X` và `O`
- Kiểm tra điều kiện thắng/thua sau mỗi lượt
- Hỗ trợ kết quả hòa khi bàn cờ đầy

---

## Chế độ chơi với máy
- AI tự động tính toán nước đi
- Máy có khả năng:
  - Chặn nước thắng của người chơi
  - Tìm nước đi tối ưu để chiến thắng
  - Đưa ra quyết định dựa trên trạng thái bàn cờ hiện tại

---

## AI sử dụng thuật toán Minimax
- Đánh giá các trạng thái của bàn cờ
- Phân tích các nước đi có thể xảy ra
- Tìm nước đi tối ưu nhất cho AI
- Tăng khả năng chiến thắng hoặc hòa

---

## Giao diện đồ họa Unity
- Bàn cờ trực quan
- Hiển thị lượt chơi hiện tại
- Hiển thị kết quả thắng/thua/hòa
- Tương tác thông qua giao diện Unity

---

# Thuật toán Minimax

Dự án sử dụng thuật toán **Minimax** để xây dựng hệ thống AI.

## Ý tưởng hoạt động
AI sẽ:
1. Mô phỏng tất cả các nước đi có thể xảy ra
2. Đánh giá điểm số cho từng trạng thái bàn cờ
3. Chọn nước đi mang lại kết quả tốt nhất

## Ưu điểm
- AI chơi thông minh hơn
- Hạn chế các nước đi sai
- Khó bị đánh bại
- Đảm bảo lựa chọn tối ưu trong nhiều tình huống

---

# Các phiên bản phát triển

## Version 1.0
- Chạy trên console
- Chế độ 2 người chơi
- Nhập vị trí từ bàn phím
- Kiểm tra thắng/thua/hòa

---

## Version 1.1
- Thêm chế độ Player vs AI
- AI chọn nước đi ngẫu nhiên

---

## Version 2.0 (Current)
- Xây dựng giao diện bằng Unity
- Thêm đồ họa cho bàn cờ
- AI sử dụng thuật toán Minimax
- Cải thiện logic xử lý trò chơi

---

# Kỹ thuật lập trình sử dụng

- Lập trình hướng đối tượng (OOP)
- Tách hàm để dễ quản lý và bảo trì
- Quản lý trạng thái bàn cờ
- Sử dụng Vector và GameObject trong Unity
- Thuật toán kiểm tra điều kiện thắng
- Thuật toán Minimax cho AI

---
# Công nghệ sử dụng

- Unity `2021.3.37f1`
- C#
- Object-Oriented Programming (OOP)
- Minimax Algorithm

---

# Hướng dẫn cài đặt và chạy game

## 1. Clone source code

```bash
git clone <your-repository-link>

