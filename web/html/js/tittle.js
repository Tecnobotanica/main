// Made by Jesus Tello @800869 in GitHub :D


function animateTitle() {
    i >= message.length - 1 ? (i = 0) : i++,
      (document.title = message[i]),
      setTimeout("animateTitle()", 2000);
  }
  var message = [
      "Tecnología Industrial",
      "Invernadero Automático"
    ],
    i = 0;
  animateTitle();