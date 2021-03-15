mapboxgl.accessToken = 'pk.eyJ1IjoibW94aXMiLCJhIjoiY2treWhlYXQ4MTA0NDJ5bzR0bjBhd3BwZyJ9.X6gP3moIllm1tgROfNDO_w';

var school = [19.0851080, 50.2517670];
var university = [18.5912394, 54.4208867];
var mansion = [18.0828310, 50.1371400];
var forest = [19.209577257794606, 50.308609288238735];
var prison = [19.2021520, 52.0608030];
var hospital = [18.6815210, 50.6658250];

function choose(button)
{
var localization = button;

var map = new mapboxgl.Map(
{
container: 'map',
style: 'mapbox://styles/mapbox/streets-v11',
center: localization,
zoom:15
});

var marker = new mapboxgl.Marker()
.setLngLat(localization)
.addTo(map);
}





