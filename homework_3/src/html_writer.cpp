#include "../api/html_writer.hpp"

#include <fmt/core.h>

#include <filesystem>

/**
 * @brief OpenDocument() will print to the standard output the begining of a
 * HTML5 file. This function should be called only once at the begining of your
 * test program.
 */

void html_writer::OpenDocument() {
  std::vector<std::string> html_opening_lines{"<!DOCTYPE html>", "<html>"};
  for (auto& line : html_opening_lines) {
    fmt::print("{}\n", line);
  }
}

// fmt::print("{:.2f}\n", 1.23456);

/**
 * @brief CloseDocument() will close the HTML5 file, this function should be
 * called only once at the end of your test program.
 */
void html_writer::CloseDocument() { fmt::print("</html>\n"); }

/**
 * @brief To make your application look nicer, you could opt for providing a
 * stylesheet using CSS for your web application.
 *
 * @param stylesheet The path where the CSS file is located, typically
 * "<path>/style.css"
 */
void html_writer::AddCSSStyle(const std::string& stylesheet) {
  fmt::print("{}\n", "<head>");
  fmt::print("{}{}{}\n", R"(<link rel="stylesheet" type="text/css" href=")",
             stylesheet, "\" />");
  fmt::print("{}\n", "</head>");
}

/**
 * @brief This function adds a Title to your web application
 *
 * @param title The string containing the title, could be as long as you wish.
 */
void html_writer::AddTitle(const std::string& title) {
  fmt::print("<title>{}</title>\n", title);
}

/**
 * @brief This will open a <body> clause in your web application.
 */
void html_writer::OpenBody() { fmt::print("<body>\n"); }

/**
 * @brief This will close a </body> clause in your web application.
 */
void html_writer::CloseBody() { fmt::print("</body>\n"); }

/**
 * @brief This will open a new row division for your application, make sure the
 * class "row" is defined in the CSS file(if any).
 */
void html_writer::OpenRow() { fmt::print("<div class=\"row\">\n"); }

/**
 * @brief This will close a  row division for your application, make sure you
 * only call this function after a OpenRow() call
 */
void html_writer::CloseRow() { fmt::print("</div>\n"); }

/**
 * @brief This function will add a new image to your web application using the
 * <img src=""> clause. It also prints the score of the image and the name of
 * the image. If it happens to be the very first image you add to your web
 * application, then,  it should be highlighted.
 *
 * @param img_path  The path to the image [png, jpg]
 * @param score     The score of the given image
 * @param highlight In case to be the very first image, this must be true.
 */
void html_writer::AddImage(const std::string& img_path, float score,
                           bool highlight) {
  if (highlight) {
    fmt::print("<div class=\"column\" style=\"border: 5px solid green;\">\n");
  } else {
    fmt::print("<div class=\"column\">\n");
  }

  const std::filesystem::path path = img_path;
  fmt::print("<h2>{}</h2>\n", path.filename().string());
  fmt::print("<img src=\"{}\" />\n", img_path);
  fmt::print("<p>score = {:.2f}</p>\n", score);
  fmt::print("</div>\n");
}
