function animateTitle() {
    i >= message.length - 1 ? (i = 0) : i++,
      (document.title = message[i]),
      setTimeout("animateTitle()", 1000);
  }
  var message = [
      "Tecnología Industrial",
      "Jesús García, Andres Tous, Candela Torreblanca, Angel Ramirez, Angel Rios, Dylan Alvarez, Juan Grande, Sergio Ruiz."
    ],
    i = 0;
  animateTitle();

  
  
