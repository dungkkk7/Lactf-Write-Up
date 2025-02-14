target = "l_alcotsft{_tihne__ifnlfaign_igtoyt}"
tagetFlag = [0] * len(target)

# Tính chiều dài của nửa chuỗi
mid = len(target) // 2

# Lặp qua nửa đầu của chuỗi và lấy các ký tự từ các vị trí chẵn
for i in range(0, mid, 1):
    tagetFlag[i] = target[i *2] 
    tagetFlag[i+mid] = target[i*2+1] 
# In kết quả dưới dạng chuỗi
print("".join(str(x) for x in tagetFlag))