# Caro3-3
Game cờ caro: 
I. Hướng dẫn cài đặt và chạy game: 
+ B1: Tải source Code và chạy trên phần mềm Unity phiên bản 2021.3.37f1;
+ B2: Chạy game: build game và chạy;


//Các phiên bản:
+ Phiên bản 1.0: Chưa có đồ hoạ, show board gồm 9 ô lập thành một bảng, chế độ 2 người chơi với nhau; 
Mỗi lượt người chơi nhập vào từ bàn phím vị trí ô mình thay đổi từ ô trống thành x/o; cập nhập xem đã đến điều kiện dừng hay chưa (có 3 ô thẳng hàng cùng x/o); khi hết cả 9 ô mà chưa có người chiến thắng thì in ra màn hình "Draw", sau mỗi lượt có người chiến thắng thì in ra tên của người chiến thắng.

+ Phiên bản 1.1: Cải tiến thêm chế độ người chơi với máy, máy tự random vị trí ô máy đánh

+ Phiên bản 2.0 (đã hoàn thành): Sử dụng đồ hoạ thông qua phần mềm Unity; xây dựng bảng, 2 chế độ 2 người chơi/ người chơi với máy; Cải tiến máy thông minh hơn khi lựa chọn nước đi để tăng khả năng chiến thắng của máy bằng cách áp dụng thuật toán minimax; lưu số điểm với mỗi trường hợp máy chọn - cuối cùng tick vào ô có khả năng chiến thắng của máy; 

II. Mô tả chung về trò chơi
+ Cờ Caro là một trò chơi bàn phổ biến, thường được chơi trên một bảng ô vuông với kích thước cố định. Trò chơi thường được chơi bởi hai người, mỗi người sử dụng một loại ký hiệu khác nhau (thường là "X" và "O") để đánh dấu các ô trên bảng.
+ Mục tiêu của trò chơi là để tạo ra một dãy liên tiếp của các ký hiệu của bạn trên bảng, theo chiều ngang, dọc hoặc chéo, trước khi đối thủ của bạn làm được điều đó. Người chơi nào đầu tiên tạo ra một dãy liên tiếp gồm một số lượng quy định trước của các ký hiệu của mình thì sẽ chiến thắng.

III. Luật chơi
+ Lượt chơi: Hai người chơi lần lượt đặt các ký hiệu của mình lên bảng, một sau một.
+ Thắng cuộc: Người chơi nào đầu tiên tạo ra một dãy liên tiếp của các ký hiệu của mình theo một hàng ngang, một hàng dọc hoặc một đường chéo thì sẽ thắng cuộc.
+ Hòa nhau: Nếu bảng đầy và không có người chơi nào thắng, trò chơi kết thúc hòa.

IV. Các kỹ thuật lập trình được sử dụng
+ Xây dựng các Class hướng đến các đối tượng trong game;
+ Sử dụng vector, tách hàm để dễ dàng quản lý
+ Sử dụng các thuật toán cơ bản kiểm tra điều kiện dừng, Minimax,...

V. Hỗ trợ
+ Sử dụng Canva để thiết kế đồ hoạ

VI. Tài liệu tham khảo: Thuật toán minimax: kênh HGTV, Kênh Hutpea, chat gpt
Link video tham khảo: https://www.youtube.com/watch?v=9wIqpACgFcI

(Souce code nằm ở file Script)

