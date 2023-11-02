# demo-project
Ở các loại xe hiện đại bây giờ sẽ có chức năng lưu trữ thông tin cài đặt xe của User vào DB. Lúc này, user chỉ cần đăng nhập vào xe bằng username và password thì hệ thống sẽ tự động cài đặt các chỉ số trên xe theo như những gì mà User này đã cài đặt trước đó. Project này sẽ mô phỏng hệ thống tự động cấu hình AVN (Audio, Video, Navigation) trên xe hơi hiện đại. 

# Description
Hệ thông cài đặt trên thiết bị AVN của ô tô được chia thành các chức năng theo các đối tượng khác nhau theo vai trò và trách nhiệm trong công việc. Trong dự án này chúng ta sẽ cài đặt 1 vài thông số trên 3 chức năng Display, Sound, General. Cụ thể như sau, sử dụng array để lưu trữ/cài đặt các dữ liệu sau:

- **Display:** Quản lý các cài đặt liên quan đến việc hiển thị trên màn hình. Trong đó có rất nhiều các chức năng nhỏ liên quan đến display, ở dự án này ta sẽ tiến hành quản lý và cài đặt các giá trị về light level, screen light level, taplo light level.
- **Sound:** Phụ trách thực hiện các công việc cài đặt về hệ thống âm thanh. Trên ô tô hệ thống âm thanh khá phức tạp và có nhiều thành phần, tuy nhiên ở dự án này ta sẽ chỉ tiến hành cài đặt và quản lý các giá trị âm thanh cho: Media volume level, Call volume level, Navigation volume level, Notification volume level.
- **General:** Gồm các cài đặt chung cho hệ thống AVN như common key, thời gian, ngôn ngữ và các chức năng chung khác … Trong dự án này ta sẽ thức hiện các công việc cài đặt cho hai chức năng chính đó là cài đặt timezone và cài đặt ngôn ngữ..

Một chiếc xe sẽ có đầy đủ cài đặt của cả Display, Sound, General. Tất cả các đối tượng trên trên đều có thông tin chung cần quản lý là Tên xe, mã số cá nhân, email người sử dụng, ODO, thông tin km cần đến để bảo dưỡng xe.

# Requirement
**Yêu cầu về giao diện**:
Phát triển ứng dụng console quản lý dữ liệu và cài đặt các chức năng trên ô tô với giao diện chính như sau:  
**Screen 1**:  
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/fd1e6582-de77-4c31-8e2b-1c6806083705)  
- Lựa chọn 1: Chuyển sang Screen 2 và nhập vào thông số cho: Display, Sound và General
- Lựa chọn 2: Chuyển sang Screen 3 và in ra các thông số của: Display, Sound và General
- Lựa chọn 3: Exit  

**Screen 2**:  
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/f90195ae-24b4-4f12-a0ea-b31bc08e5999)  

Tại đây, sẽ nhập vào thông tin của users (tên, email, code) và các chỉ số của Display (front light, screen light, taplo light), Sound (Media, Call, Notification) and General (Timezone, Language)  
Sẽ có 2 trường hợp xảy ra lúc này:
- Nếu thông tin của user đã tồn tại trong DB, thì thông báo cho user và overwrite giá trị cũ.
- Nếu thông tin của user chưa có trong DB, thì thông báo và append dữ liệu vào DB.

Một ví dụ cho việc pops up thông tin user ở Screen 2:
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/f486f2d2-f2cd-4b27-8e01-224444798fe1)

Nếu người dùng chọn y thì sẽ tiếp tục hiển thị để người dùng nhập vào dữ liệu của chiếc xe tiếp theo. Nếu người dùng chọn n thì quay trở lại (MH-1)

**Screen 3**:  
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/f43f5c9b-cf96-4bc0-9f5a-7a34640622dc)  
Sau đó đối với các lựa chọn 1-2-3 thì đưa ra thông tin của các chức năng đơn lẻ. Ví dụ (các chức năng khác tương tự)  
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/28aad7da-e83c-435a-9f3c-0ea4c88d4eb7)  
Với lựa chọn 4 thì in tất cả thông tin Display, General, Sound theo tên chủ xe hoặc mã số cá nhân được nhâp vào:  
![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/85555d69-01bf-44af-ba20-dadbb3e804c0)  

**Yêu cầu về chức năng**:
- Mã số cá nhân phải là 1 số có đủ 8 chữ số, ví dụ 11223344 hoặc 00112233 hoặc 22331100.
- Thông tin của user trong DB phải được sắp xếp theo thứ tự tăng dần
- Email phải là một chuỗi có định dạng abc@xyz.def
- Hàm, lớp thiết kế trong chương trình phải thể hiện được tính kế thừa và tính đa hình.
- Riêng chức năng General có phần lựa chọn ngôn ngữ và timezone được được cung cấp sẵn như list dưới đây.

 Khi người dùng cài đặt cho chức năng General, sẽ cần phải list ra timezones/languages để người dùng lựa chọn. Như minh họa dưới đây:  
 ![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/142fee7b-4888-4e21-b377-9a097ec026b2)  
 ![image](https://github.com/longtruong-rvc/demo-project/assets/97014809/5a7b24e2-95ef-47ce-b378-399543be6cf0)  

 







