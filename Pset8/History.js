function show(element)
        {
            var content = ["school", "university", "mansion", "forest", "prison", "hospital"];
            for (var i = 0; i < content.length; i++)
            {
                var x = document.getElementsByClassName(content[i] + "_text");
                var y = document.getElementsByClassName(content[i] + "_title");
                if (window.getComputedStyle(x[0]).display == "block")
                {
                    x[0].style.display = "none";
                }
                if (window.getComputedStyle(y[0]).display == "block")
                {
                    y[0].style.display = "none";
                }

                if (content[i] == element)
                {
                    console.log("test");
                    x[0].style.display = "block";
                }

                if (content[i] == element)
                {
                    console.log("test");
                    y[0].style.display = "block";
                }
            }
        }
