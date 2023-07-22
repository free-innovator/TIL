# 2023-07-20

## CNN (이미지 전처리)
* `import cv2 as cv`
    * `img = cv.imread("../images/headache.png")`
    * `r, g, b = cv.split(img)`
    * `img_rgb = cv.merge([b, g, r])`
    * `img_green = img[:, :, 1]`
    * `cv.waitKey()`
    * `cv.destroyAllWindows()`
    * `cv.vconcat([img_blue, img_green, img_red])`
    * `cv.hconcat([img_blue, img_green, img_red])`
    * `cv.Canny(img01, 0, 255)`
    * cvtColor
        * `cv.cvtColor(img, cv.COLOR_BGR2RGB)`
        * `cv.cvtColor(img, cv.COLOR_BGR2GRAY)`
    * resize
        * `cv.resize(img, dsize=(500, 500))`
        * `cv.resize(img_center, (img.shape[0], img.shape[1]))`
    * rotate
        * `cv.rotate(img_plot, cv.ROTATE_90_CLOCKWISE)`
        * `cv.rotate(img_plot, cv.ROTATE_90_COUNTERCLOCKWISE)`
    * flip
        * `cv.flip(img_plot, 0)`
        * `cv.flip(img_plot, 1)`
        * `cv.flip(img_plot, -1)`
    * threshold
        * `th, img_th = cv.threshold(img, 100, 255, cv.THRESH_BINARY)`
        * `th, img_th = cv.threshold(img[:, :, 2], 0, 255, cv.THRESH_OTSU)`
    * bitwise
        * `cv.bitwise_and(img, img, mask=img_blue_mask)`
        * `cv.bitwise_and(img01, img02)`
        * `cv.bitwise_or(img01, img02)`
        * `cv.bitwise_xor(img01, img02)`
        * `cv.bitwise_not(img01)`
    * blur
        * `kernel = np.ones((5, 5), np.float32) / 25`
        * `cv.filter2D(img_gray, -1, kernel)`
        * `cv.blur(img_gray, (5, 5))`
        * `cv.GaussianBlur(img_gray, (15, 15), 0)`
        * `cv.medianBlur(img, 5)`
    * 평탄화 (작은 점들을 뭉개는 방법들)
        * `cv.bilateralFilter(img, 20, 250, 100)`
        * `cv.erode(img, kernel, iterations=2)`
        * `cv.dilate(img, kernel, iterations=2)`
        * `cv.morphologyEx(img_th, cv.MORPH_GRADIENT, kernel)`
    * ...
        * `cv.getRotationMatrix2D((w/2, h/2), 45, 0.5)`
        * `cv.warpAffine(img, mat, (w, h), borderValue=(0, 128, 255))`
        * `cv.warpAffine(img, mat, (w, h), borderMode=cv.BORDER_TRANSPARENT, dst=dst)`
        * `cv.warpAffine(img, mat, (w, h), borderMode=cv.BORDER_REPLICATE)`
        * `cv.warpAffine(img, mat, (w, h), borderMode=cv.BORDER_WRAP)`