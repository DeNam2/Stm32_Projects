# Stm32_Projects
*) Dựa vào kết quả nghiên cứu về sinh học mắt người: Đối với video hay ảnh động, mắt của chúng ta chỉ nhìn(phân biệt) các ảnh riêng lẻ hay ảnh không nét(chuyển động bị cong) khi tốc độ nhỏ hơn 24 fps(frames per second), tức mắt người chỉ nhìn được tối đa 24 ảnh trên giây, quá nó là không nhìn thấy gì.
Phương pháp quét led:
- Tại một thời điểm chỉ có 1 led được sáng và các led kia tắt.
- Ở đây ta sẽ lập trình tốc độ xuất logic cho led7seg sáng thay phiên nhau nhanh để đánh lừa mắt tưởng tại cùng một thời điểm cả 2 led đều sáng.
- Ở đây có ý nghĩa 2 lần quét:
    +) TH1: Tại 1 thời điểm quét qua 2 led sao cho người nhìn tưởng 2 led sáng đồng thời
    +) TH2: Thêm nhiều vòng lặp để bật tắt liên tục led sao cho hiện đủ lâu để nhìn thông tin hiển thị trên led(Quét một led bật tắt đi nhiều lần để duy trì một ảnh        tĩnh đủ để ta xem thông tin) 
