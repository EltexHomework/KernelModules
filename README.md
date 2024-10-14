# Задание №20 - Модули ядра Linux
## Сборка проекта
Для сборки проекта необходимо воспользоваться утилитой `make` в директории `task1/src`.
## Процесс сборки модуля
В процессе сборки модуля были использованы следующие команды:
- `make` - сборка модуля ядра
- `sudo insmod test.ko` - загрузка модуля ядра
- `sudo dmesg | tail -n 10` - вывод сообщений ядра
![Screenshot from 2024-10-09 20-21-52](https://github.com/user-attachments/assets/e620d1b3-2cb1-4682-b33f-af4df38eb853)
- `sudo mknod test c 511 0` - создание файла символьного устройства с мажоным номером 511 и минорным 0
- `cat test` - вывод содержимого переменной
- `echo "asdasd" > test` - запись содержимого в переменную
- `sudo rmmod test` - выгрузка модуля ядра
![Screenshot from 2024-10-09 20-23-11](https://github.com/user-attachments/assets/8968642b-1fd3-4133-9f32-5eaa8d49de78)
## Работа с ФС proc и Sys
Был написан модуль для работы с файловыми системами proc и Sys. Результаты тестирования:
- Сборка и загрузка модуля
![Screenshot from 2024-10-14 19-05-50](https://github.com/user-attachments/assets/f0d28413-42f2-4db6-ab29-fd245cacf041)
- Работа с файловой системой proc
![Screenshot from 2024-10-14 19-07-01](https://github.com/user-attachments/assets/820d197a-9067-4d43-a446-f578c6128e0d)
- Работа с файловой системой Sys
![Screenshot from 2024-10-14 19-07-51](https://github.com/user-attachments/assets/acebab8a-397b-4c27-9980-327e01e934be)
