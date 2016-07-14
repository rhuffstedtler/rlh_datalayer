(function ($) {
    Drupal.behaviors.alert = {
        attach: function (context, settings) {
            var myHelper = new DataLayerHelper(dataLayer);
            //the helper actually seems to be only for getting data, not pushing
            //I don't quite yet get the value it provides
            dataLayer.push({
                'someEvent' : 'someValue'
            });
            //alert('Value I just added: ' + myHelper.get('someEvent'));
        }
    };
})(jQuery);