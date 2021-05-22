#include "../api/image_browser.hpp"

#include "../api/html_writer.hpp"
#include "fmt/core.h"

/// Some Utility Name Types that will make the code more readable
// using ScoredImage = std::tuple<std::string, float>;
// using ImageRow = std::array<ScoredImage, 3>;

/**
 * @brief This function is in charge to add a full row in the web application, A
 * row consists always of 3 columns, each one contains one image with a given
 * score.
 *
 * @param row          A set with 3 images plus the score of each one.
 * @param first_row    If it's the very first row, the first image should be
 * highlighted.
 */
void image_browser::AddFullRow(const image_browser::ImageRow& row,
                               bool first_row) {
  html_writer::OpenRow();
  for (const auto& col : row) {
    const auto& [path, score] = col;
    html_writer::AddImage(path, score, first_row);
    if (first_row) {
      first_row = false;
    }
  }
  html_writer::CloseRow();
}

/**
 * @brief Create a Image Browser application, This function should be completely
 * self containded and should take all the necessary actions to create an image
 * web browser application.
 *
 * @param title      The title of the web application.
 * @param stylesheet The CSS style, if any.
 * @param rows       A set of ImageRow, with all the given images to show.
 */
void image_browser::CreateImageBrowser(
    const std::string& title, const std::string& stylesheet,
    const std::vector<image_browser::ImageRow>& rows) {
  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  bool first = true;
  for (const auto& row : rows) {
    if (first) {
      image_browser::AddFullRow(row, first);
      first = false;
    } else {
      image_browser::AddFullRow(row);
    }
  }
  html_writer::CloseBody();
  html_writer::CloseDocument();
}
