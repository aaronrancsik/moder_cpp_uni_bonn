
#include "../api/html_writer.hpp"
#include "../api/image_browser.hpp"
int main() {
  const std::vector<std::array<image_browser::ScoredImage, 3>> rows = {
      image_browser::ImageRow{image_browser::ScoredImage{"data/000000.png", 1},
                              image_browser::ScoredImage{"data/000100.png", 1},
                              image_browser::ScoredImage{"data/000200.png", 1}},
      image_browser::ImageRow{image_browser::ScoredImage{"data/000300.png", 1},
                              image_browser::ScoredImage{"data/000400.png", 1},
                              image_browser::ScoredImage{"data/000500.png", 1}},
      image_browser::ImageRow{
          image_browser::ScoredImage{"data/000600.png", 1},
          image_browser::ScoredImage{"data/000700.png", 1},
          image_browser::ScoredImage{"data/000800.png", 1}}};
  image_browser::CreateImageBrowser("My super web page", "style.css", rows);
  return 0;
}