library(imager)

#' read in image and change them into a depth map
#' @param path path of the image
#' @param cutoff cutoff the grayscale, from 0 to 1
#' @return NULL
#' @export

getdepthmap <- function(path, cutoff = 0.5){
        img <- imager::load.image(path)
        img2 <- imager::grayscale(img)
        px <- img2 > cutoff
        return(px)
}

#' read in image and change them into magic eye
#' @param img cimg object
#' @param shift shift of magic eye, default 0.15
#' @return NULL
#' @export

getme <- function(img,shift=0.15){
        d <- dim(img)
        mask <- matrix(as.numeric(img),d[1],d[2])
        i <- imager::as.cimg(mask,dim=c(d[1],d[2],d[3],1))
        c1 <- matrix(stats::runif(50*50,0,1),50,50)
        o <- getmagiceye(t(mask), c1, shift)
        o <- t(o)
        o <- imager::as.cimg(o,dim=c(d[1],d[2],d[3],1))
        return(o)
}

#' read in text
#' @param text text
#' @return NULL
#' @export

getmet <- function(text = 'yufree'){
        bg <- imager::imfill(1000,1000,val=1)
        o <- imager::implot(bg,text(500,500,text,cex=20))
        return(1-o)
}
