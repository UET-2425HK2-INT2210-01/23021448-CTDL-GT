Bài 1:
Biểu thức chính quy / <[^ > ] + > / sẽ khớp với chuỗi :
1. < an xml tag >
3. < / closetag >
5. < with attribute = ”77” >

Bài 2:
Biểu thức chính quy / a.[bc] + / sẽ khớp với chuỗi :
1.abc
2.abbbbbbbb
3.azc
4.abcbcbcbc
6.azccbbbbcbccc

Bài 3:
Giải thích biểu thức :
(very)+→ phải có ít nhất một từ "very " đứng trước.
(fat) ? → có thể có hoặc không từ "fat " sau "very".
(tall | ugly) → bắt buộc phải có "tall" hoặc "ugly".
" man" → phải kết thúc bằng " man".

Biểu thức chính quy / (very)+(fat) ? (tall | ugly) man / khớp với :
3. very very fat ugly man
4. very very very tall man

Bài 4:
Biểu thức chính quy khớp đúng và chỉ đúng chuỗi có dạng "abc.def.ghi.jkx:
^ .{3}\..{3}\..{3}\..{3}$

Bài 5:
Biểu thức khớp các số điện thoại ở các định dạng :
^ (\(\d{ 3 }\) | \d{ 3 })[\s. - ] ? \d{ 3 }[\s. - ] ? \d{ 4 }$

Bài 6:
Biểu thức regular expression thỏa mãn tất cả các điều kiện :
^ [a - zA - Z0 - 9] + ([_ - ][a - zA - Z0 - 9] + ) * $