(function() {
  var ad = ['.room-ad-top', '#js-live-room-normal-right', '.PlayerSub']
  for (var el in ad) {
    document.querySelector(ad[el]).innerHTML = ''
  }
}())