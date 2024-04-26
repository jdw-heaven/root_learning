#include <TFile.h>
#include <TH1F.h>
#include <TRandom3.h>
#include <iostream>

int example() {
    // 创建一个新的 ROOT 文件
    TFile *file = new TFile("example.root", "RECREATE");

    // 检查文件是否成功创建
    if (file->IsZombie()) {
        std::cerr << "Error: Cannot create file" << std::endl;
        return 1;
    }

    // 创建一个直方图
    TH1F *histogram = new TH1F("histogram", "Gaussian Distribution", 100, -5, 5);

    // 使用 TRandom3 生成一些正态分布的随机数来填充直方图
    TRandom3 rand;
    for (int i = 0; i < 1000000; ++i) {
        histogram->Fill(rand.Gaus(0, 1));
    }

    // 将直方图写入 ROOT 文件
    histogram->Write();

    // 关闭文件
    file->Close();

    // 删除对象，释放内存
    //delete histogram;
    delete file;

    return 0;
}