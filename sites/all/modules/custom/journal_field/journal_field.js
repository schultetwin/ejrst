(function ($) {

  Drupal.behaviors.journalField = {
    attach: function (context, settings) {
      $('.journal-field-special-issue-check').each(function (index, element) {
        if ($(this).children('.form-type-checkbox').children('input').attr('checked')) {
          $(this).next('.journal-field-special-issue-subject').show();
        }
        else {
          $(this).next('.journal-field-special-issue-subject').hide();
        }
      });
      $('.journal-field-special-issue-check', context).change(function () {
        $(this).next('.journal-field-special-issue-subject').toggle('show');
      });
    }
  }
})(jQuery);
