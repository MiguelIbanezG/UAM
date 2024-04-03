
from .models import Book, Author, BookInstance, Genre
from django.views import generic


# Create your views here.

from django.contrib.auth.mixins import LoginRequiredMixin

from django.contrib.auth.decorators import permission_required
from django.contrib.auth.decorators import login_required

from django.contrib.auth.mixins import PermissionRequiredMixin


import datetime

from django.shortcuts import render, get_object_or_404
from django.http import HttpResponseRedirect
from django.urls import reverse

from catalog.forms import RenewBookForm
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from django.urls import reverse_lazy


def index(request):

    num_books = Book.objects.all().count()

    num_instances = BookInstance.objects.all().count()

    num_instances_available = BookInstance.objects.filter(
        status__exact='a').count()

    num_visits = request.session.get('num_visits', 0)
    request.session['num_visits'] = num_visits + 1

    num_authors = Author.objects.count()

    num_genres = Genre.objects.count()

    num_aintitle = Book.objects.filter(title__icontains='a').count()

    context = {
        'num_books': num_books,
        'num_instances': num_instances,
        'num_instances_available': num_instances_available,
        'num_authors': num_authors,
        'num_visits': num_visits,
        'num_genres': num_genres,
        'num_aintitle': num_aintitle,
    }

    return render(request, 'index.html', context=context)

# def book_detail_view(request, primary_key):
    # try:
    #   book = Book.objects.get(pk=primary_key)
    # except Book.DoesNotExist:
    #   raise Http404('Book does not exist')

    # return render(request, 'catalog/book_detail.html', context={'book': book})


def book_detail_view(request, primary_key):
    book = get_object_or_404(Book, pk=primary_key)
    return render(request, 'catalog/book_detail.html', context={'book': book})


class BookListView(generic.ListView):
    model = Book

    # override viewset
    # def get_queryset(self):
    #    return Book.objects.filter(title__icontains='war')[:5] # Get 5 books containing the title war

    # override attribute from book
    # def get_context_data(self, **kwargs):
    # Call the base implementation first to get the context
    #   context = super(BookListView, self).get_context_data(**kwargs)
    # Create any data and add it to the context
    #   context['some_data'] = 'This is just some data'
    #   return context

    paginate_by = 3


class BookDetailView(generic.DetailView):
    model = Book


def author_detail_view(request, primary_key):
    author = get_object_or_404(Author, pk=primary_key)
    return render(request, 'catalog/author_detail.html', context={'author': author})


class AuthorListView(generic.ListView):
    model = Author
    paginate_by = 10


class AuthorDetailView(generic.DetailView):
    model = Author


class LoanedBooksByUserListView(LoginRequiredMixin, generic.ListView):
    """Generic class-based view listing books on loan to current user."""
    model = BookInstance
    template_name = 'catalog/bookinstance_list_borrowed_user.html'
    paginate_by = 10

    def get_queryset(self):
        return (
            BookInstance.objects.filter(borrower=self.request.user)
            .filter(status__exact='o')
            .order_by('due_back')
        )


class LoanedBooksByLibrarianListView(PermissionRequiredMixin, generic.ListView):
    """Generic class-based view listing books on loan to current user."""
    model = BookInstance
    template_name = 'catalog/bookinstance_list_borrowed_all.html'
    paginate_by = 10

    permission_required = 'catalog.can_mark_returned'

    def get_queryset(self):
        return (
            BookInstance.objects.filter(status__exact='o')
            .order_by('due_back')
        )


@login_required
@permission_required('catalog.can_mark_returned', raise_exception=True)
def renew_book_librarian(request, pk):
    book_instance = get_object_or_404(BookInstance, pk=pk)

    # If this is a POST request then process the Form data
    if request.method == 'POST':

        # Create a form instance and populate it with data from the request (binding):
        form = RenewBookForm(request.POST)

        # Check if the form is valid:
        if form.is_valid():
            # process the data in form.cleaned_data as required (here we just write it to the model due_back field)
            book_instance.due_back = form.cleaned_data['renewal_date']
            book_instance.save()

            # redirect to a new URL:
            return HttpResponseRedirect(reverse('all-borrowed'))

    # If this is a GET (or any other method) create the default form.
    else:
        proposed_renewal_date = datetime.date.today() + datetime.timedelta(weeks=3)
        form = RenewBookForm(initial={'renewal_date': proposed_renewal_date})

    context = {
        'form': form,
        'book_instance': book_instance,
    }

    return render(request, 'catalog/book_renew_librarian.html', context)

    '''Lo mismo que arriba pero simplificado
    from django.forms import ModelForm

    from catalog.models import BookInstance

    class RenewBookModelForm(ModelForm):
        def clean_due_back(self):
        data = self.cleaned_data['due_back']

        # Check if a date is not in the past.
        if data < datetime.date.today():
            raise ValidationError(_('Invalid date - renewal in past'))

        # Check if a date is in the allowed range (+4 weeks from today).
        if data > datetime.date.today() + datetime.timedelta(weeks=4):
            raise ValidationError(_('Invalid date - renewal more than 4 weeks ahead'))

        # Remember to always return the cleaned data.
        return data

        class Meta:
            model = BookInstance
            fields = ['due_back']
            labels = {'due_back': _('Renewal date')}
            help_texts = {'due_back': _('Enter a date between now and 4 weeks (default 3).')}
    '''


class AuthorCreate(PermissionRequiredMixin, CreateView):
    model = Author
    fields = ['first_name', 'last_name', 'date_of_birth', 'date_of_death']
    initial = {'date_of_death': '11/06/2020'}
    permission_required = 'catalog.can_mark_returned'


class AuthorUpdate(PermissionRequiredMixin, UpdateView):
    model = Author
    # Not recommended (potential security issue if more fields added)
    fields = '__all__'
    permission_required = 'catalog.can_mark_returned'


class AuthorDelete(PermissionRequiredMixin, DeleteView):
    model = Author
    success_url = reverse_lazy('authors')
    permission_required = 'catalog.can_mark_returned'


class BookCreate(PermissionRequiredMixin, CreateView):
    model = Book
    fields = ['title', 'author', 'summary', 'isbn', 'genre', 'language']
    permission_required = 'catalog.can_mark_returned'


class BookUpdate(PermissionRequiredMixin, UpdateView):
    model = Book
    # Not recommended (potential security issue if more fields added)
    fields = '__all__'
    permission_required = 'catalog.can_mark_returned'


class BookDelete(PermissionRequiredMixin, DeleteView):
    model = Book
    success_url = reverse_lazy('books')
    permission_required = 'catalog.can_mark_returned'
