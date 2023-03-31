TAI'de Tamamladığım Projeler ve Uygulamalar

* Fiziksel Bellek Tahsisi Projesi: 
  Bu projede linked list yapısını kullanarak freeWithAddr, allocateWithAddr ve allocateWithoutAddr fonksiyonlarının implemantasyonu yapılarak oluşturulan algoritma
  Atabey Şahin tarafından verilen test caseler üzerinde denendi ve bu testler başarıyla sonuçlandı. Linked list nodelarında müsait olan hafıza alanlarının başlangıç ve 
  bitiş adresleri tutulur. Yukarıda bahsettiğim fonksiyonlar kullanılarak bu adresler üzerinde işlemler yapılır. Kod üzerinde bu fonksiyonlar yorum satırlarıyla detaylı 
  bir şekilde açıklanmmıştır.
  
* Reverse String Uygulaması: 
  Bu uygulama kullanıcan bir string girmesini istiyor ve girilen stringin tersini oluşturarak print ediyor. Tersini elde etme işlemini gerçekleştirebilmek için for loop 
  ile string karakterleri üzerinde gezilir ve temp değişkeni kullanarak baştaki ve sondaki karakterlerin değişimi sağlanır.

* Binary Search Tree Uygulaması: 
  Bu uygulamada ise temel binary search tree fonksiyonları implemente edilmiştir. Tree üzerindeki datalar soldan başlayarak küçükten büyüğe doğru nodelar üzerinde bir 
  ağaç yapısında tutulur. Yeni bir data eklenmek istendiğinde datanın yeri bulunana kadar insert fonksiyonu recursive olarak çağılır, bulunduğunda data oraya entegre 
  edilir. Ağaç üzerinde gezebilmek için travInOrder, travPreOrder ve travPostOrder fonksiyonları kullanılır. findMin fonksiyonu ağacın en soldaki node'unu; fingMax is 
  ağacın en sağdaki node'unu vermektedir. Ayrıca tree üzerindeki bir datanın path'ini veren searchPath fonksiyonu da yazıldı.

* Bubble Sort Uygulaması: 
  Bu uygulamanın amacı bir arrayi bubble sort metodunu kullanarak sıralamaktır. İlk indexten başlayarak sonraki indexle bire bir karşılaştırma yapılarak arrayin son 
  indexine kadar gidilir. Tüm arrayler sıralı hale gelene kadar karşılaştırmalar yapılır ve indexler arasında gerekli değişiklikler yapılır.

* Merge Sort Uygulaması: 
  Bu uygulamanın amacı ise bir arrayi merge sort metodunu kullanarak sıralamaktır. Recursion kullanılarak array sürekli iki parçaya bölünür. En küçük parçalardan 
  karşılaştırmaya başlayarak bütüne gidilir. Detaylı açıklama kodun yorum satırlarında mevcuttur.

* Process Fonksiyonları 1 ve 2 Uygulaması: 
  Child process oluşturma, parent ve child processlerin ID'lerini ve oluşturulma zamanlarını yazdırma, child process kill etme fonksiyonları uygulandı. Child processler 
  oluşturulduktan sonra parent processi kill edildi.

* Thread Fonksiyonları 1 ve 2 Uygulaması: 
  Multithreading applikasyonları üzerinde çalışıldı. Multithreading kullanılarak dosya okuma yazma işlemleri yapıldı. Asenkronize şekilde yazılan kodlar mutex 
  kullanılarak senkronize hale getirildi.
