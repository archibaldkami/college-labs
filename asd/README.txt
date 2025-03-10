Для запуску програми на OS Arch Linux необхідно завантажити пакети "qt6-base", "qt6-declarative", "cmake"
Завантажити їх можна наступною командою "sudo pacman -S qt6-base qt6-declarative cmake"
Далі виконуємо наступні команди:
 
git clone https://github.com/archibaldkami/college-labs.git
cd college-labs/asd
mkdir build
cd build
cmake ..
make && ./app