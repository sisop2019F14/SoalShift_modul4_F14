# SoalShift_modul4_F14

Atta menginginkan nama file system yang akan kalian buat adalah “AFSHiaAP”, yang nama kepanjangannya adalah AHHA’s File System: Hierarchical and Advanced Protection. Berikut ini kebutuhan yang harus kalian penuhi:

-1

Semua nama file dan folder harus terenkripsi

Enkripsi yang Atta inginkan sangat sederhana, yaitu Caesar cipher. Namun, Kusuma mengatakan enkripsi tersebut sangat mudah dipecahkan. Dia menyarankan untuk character list diekspansi,tidak hanya alfabet, dan diacak. Berikut character list yang dipakai:


qE1~ YMUR2"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\8s;g<{3.u*W-0


Misalkan ada file bernama “halo” di dalam folder “INI_FOLDER”, dan key yang dipakai adalah 17, maka:

“INI_FOLDER/halo” saat belum di-mount maka akan bernama “n,nsbZ]wio/QBE#”, saat telah di-mount maka akan otomatis terdekripsi kembali menjadi “INI_FOLDER/halo” .

Perhatian: Karakter ‘/’ adalah karakter ilegal dalam penamaan file atau folder dalam *NIX, maka dari itu dapat diabaikan

Jawab:

- membuat fungsi untuk membaca folder AFSHiaAP yang terenkripsi

- membuat fungsi untuk melakukan dekripsi, lalu ditaruh pada folder baru.

- membuat fungsi untuk mengambil atribut file dari folder baru(yang telah di deskripsi), lalu di enkripsi (untuk merujuk pada file AFSHiaAP), sehingga atribut file pada folder baru yang telah di deskripsi sama dengan file AFSHiaAP.

-2

Semua file video yang tersimpan secara terpecah-pecah (splitted) harus secara otomatis tergabung (joined) dan diletakkan dalam folder “Videos”

Urutan operasi dari kebutuhan ini adalah:

a. Tepat saat sebelum file system di-mount

- Secara otomatis folder “Videos” terbuat di root directory file system

- Misal ada sekumpulan file pecahan video bernama “computer.mkv.000”, “computer.mkv.001”, “computer.mkv.002”, dst. Maka secara otomatis file pecahan tersebut akan di-join menjadi file video “computer.mkv”.
Untuk mempermudah kalian, dipastikan hanya video file saja yang terpecah menjadi beberapa file. File pecahan tersebut dijamin terletak di root folder fuse

-Karena mungkin file video sangat banyak sehingga mungkin saja saat menggabungkan file video, file system akan membutuhkan waktu yang lama untuk sukses ter-mount. Maka pastikan saat akan menggabungkan file pecahan video, file system akan membuat 1 thread/proses(fork) baru yang dikhususkan untuk menggabungkan file video tersebut

-Pindahkan seluruh file video yang sudah ter-join ke dalam folder “Videos”

-Jangan tampilkan file pecahan di direktori manapun

b. Tepat saat file system akan di-unmount

-Hapus semua file video yang berada di folder “Videos”, tapi jangan hapus file pecahan yang terdapat di root directory file system

-Hapus folder “Videos” 

Jawab:


-3

Sebelum diterapkannya file system ini, Atta pernah diserang oleh hacker LAPTOP_RUSAK yang menanamkan user bernama “chipset” dan “ic_controller” serta group “rusak” yang tidak bisa dihapus. Karena paranoid, Atta menerapkan aturan pada file system ini untuk menghapus “file bahaya” yang memiliki spesifikasi:

Owner Name     : ‘chipset’ atau ‘ic_controller’

Group Name    : ‘rusak’

Tidak dapat dibaca

Jika ditemukan file dengan spesifikasi tersebut ketika membuka direktori, Atta akan menyimpan nama file, group ID, owner ID, dan waktu terakhir diakses dalam file “filemiris.txt” (format waktu bebas, namun harus memiliki jam menit detik dan tanggal) lalu menghapus “file bahaya” tersebut untuk mencegah serangan lanjutan dari LAPTOP_RUSAK.

Jawab:

- membuat fungsi untuk melakukan enkripsi dari folder baru untuk mendapatkan path dari file folder AFSHiaAP.

-membuat fungsi untuk membaca owner dan group name dengan ketentuan seperti di soal, lalu dilihat apakah file tersebut bisa dibaca atau tidak.

-jika Owner Name bernama ‘chipset’ atau ‘ic_controller’ dan Group Name bernama ‘rusak’, dan file tidak bisa dibaca, maka file tersebut dihapus.

-4

Pada folder YOUTUBER, setiap membuat folder permission foldernya akan otomatis menjadi 750. Juga ketika membuat file permissionnya akan otomatis menjadi 640 dan ekstensi filenya akan bertambah “.iz1”. File berekstensi “.iz1” tidak bisa diubah permissionnya dan memunculkan error bertuliskan “File ekstensi iz1 tidak boleh diubah permissionnya.”

Jawab:

- membuat fungsi untuk melakukan enkripsi dari folder baru untuk mendapatkan path dari file folder AFSHiaAP.

- membuat funsi xmp_mkdir untuk bisa membuat folder, lalu ganti permission menjadi 750

- membuat fungsi utimens, create, dan write untuk membuat file baru, lalu ubah permission menjadi 640, dan tambahkan ekstensi .iz1.

-5

Ketika mengedit suatu file dan melakukan save, maka akan terbuat folder baru bernama Backup kemudian hasil dari save tersebut akan disimpan pada backup dengan nama namafile_[timestamp].ekstensi. Dan ketika file asli dihapus, maka akan dibuat folder bernama RecycleBin, kemudian file yang dihapus beserta semua backup dari file yang dihapus tersebut (jika ada) di zip dengan nama namafile_deleted_[timestamp].zip dan ditaruh ke dalam folder RecycleBin (file asli dan backup terhapus). Dengan format [timestamp] adalah yyyy-MM-dd_HH:mm:ss

Jawab:

