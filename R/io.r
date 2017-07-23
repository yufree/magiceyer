library(imager)

#' read in image and change them into a depth map
#' @param path path of the image
#' @param cutoff cutoff the grayscale, from 0 to 1
#' @return NULL
#' @export

getdepthmap <- function(path, cutoff = 0.5){
        img <- load.image(path) %>%
                grayscale()
        px <- img > cutoff
        return(px)
}
