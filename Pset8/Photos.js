function show(element)
            {
                var images = ["school_img", "university_img", "mansion_img", "forest_img", "prison_img", "hospital_img"];
                for (var i = 0; i < images.length; i++)
                {
                    var all = document.querySelectorAll("." + images[i])
                    for (var j = 0; j < all.length; j++)
                    {
                        var x = document.getElementsByClassName(images[i])[j];
                        if (window.getComputedStyle(x).display == "block")
                        {
                            document.getElementsByClassName(images[i])[j].style.display = "none";
                        }
                        if (images[i] == element)
                        {
                            for (var k = 0; k < all.length; k++)
                            {
                                document.getElementsByClassName(images[i])[k].style.display = "block";
                            }
                        }
                    }
                }
            }

$('img[data-enlargeable]').addClass('img-enlargeable').click(function(){
var src = $(this).attr('src');
var modal;
function removeModal(){ modal.remove(); $('body').off('keyup.modal-close'); }
modal = $('<div>').css({
    background: 'RGBA(0,0,0,.5) url('+src+') no-repeat center',
    backgroundSize: 'contain',
    width:'100%', height:'100%',
    position:'fixed',
    zIndex:'10000',
    top:'0', left:'0',
    cursor: 'zoom-out'
}).click(function(){
    removeModal();
}).appendTo('body');
//handling ESC
$('body').on('keyup.modal-close', function(e){
  if(e.key==='Escape'){ removeModal(); }
});
});
