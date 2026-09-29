# Module Tiếp nhận & Xếp hàng Khám bệnh MedCare Clinic

## 1. Phân tích bài toán (I/O)
*   **Dữ liệu đầu vào (Input):**
    *   Mảng `tuoi_benh_nhan[4]`: Lưu trữ số tuổi của 4 bệnh nhân.
    *   Mảng `co_bao_hiem[4]`: Lưu trữ trạng thái BHYT của 4 bệnh nhân (1 hoặc 0).
*   **Quá trình xử lý (Process):**
    *   Kiểm tra tính hợp lệ của tuổi (0 < tuổi <= 120) và trạng thái BHYT (chỉ nhận 0 hoặc 1).
    *   Tính toán phí khám dựa trên trạng thái BHYT hợp lệ.
    *   Phân loại luồng (Ưu tiên / Thường / Lỗi dữ liệu).
    *   Cộng dồn doanh thu và đếm số ca ưu tiên.
*   **Dữ liệu đầu ra (Output):**
    *   Mảng `phi_kham[4]`: Phí khám thực tế của từng bệnh nhân sau khi áp dụng các quy tắc.
    *   Bảng thông tin chi tiết từng bệnh nhân (Độ tuổi, BHYT, Phí khám, Luồng phân loại).
    *   Tổng doanh thu ca khám và Tổng số ca ưu tiên.

## 2. Đề xuất giải pháp
*   **Cấu trúc lưu trữ:** Sử dụng 3 mảng song song (parallel arrays) có cùng kích thước (4 phần tử) để lưu thông tin tuổi, bảo hiểm và phí khám tương ứng với từng chỉ số (từ 0 đến 3) của bệnh nhân.
*   **Kiểm soát dữ liệu (Data Validation):** 
    *   **Trường hợp Tuổi:** Dùng lệnh `if` kiểm tra biên. Nếu nằm ngoài `(0, 120]`, gán trực tiếp phí khám = `0` và bỏ qua các logic tính toán khác cho bệnh nhân này.
    *   **Trường hợp BHYT:** Dùng lệnh `if` kiểm tra khác `0` và khác `1`. Nếu vi phạm, gán đè giá trị về `0` (Không BHYT) trước khi đưa vào công thức tính tiền.

## 3. Thiết kế các bước thực hiện
*   **Bước 1:** Khai báo các mảng dữ liệu và biến tổng hợp (`tong_doanh_thu`, `so_ca_uu_tien`).
*   **Bước 2:** Sử dụng vòng lặp (hoặc gán tuần tự) để nhập dữ liệu tuổi và BHYT cho 4 bệnh nhân.
*   **Bước 3:** Duyệt mảng để xử lý logic:
    *   Kiểm tra lỗi tuổi. Nếu lỗi -> xử lý ngoại lệ.
    *   Nếu tuổi hợp lệ -> Kiểm tra và nắn chỉnh lỗi BHYT -> Tính phí khám -> Lưu vào mảng `phi_kham` -> Kiểm tra độ tuổi ưu tiên (>70).
*   **Bước 4:** In báo cáo chi tiết từng bệnh nhân và các số liệu tổng hợp.