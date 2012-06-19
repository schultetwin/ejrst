<?php

/*
 * Ejrst frontpage
 */
function ejrst_custom_front_page() {
  return array('#markup' => views_embed_view('frontpage_journal_slideshow'));
}
